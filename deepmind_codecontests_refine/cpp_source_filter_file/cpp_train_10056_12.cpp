#include <bits/stdc++.h>
using namespace std;
void readfile() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long long nmax = (long long)5e5 + 20;
long long n;
map<long long, long long> has;
vector<long long> nums;
map<long long, long long> pows;
void pre() {
  long long p = 1;
  for (long long i = (long long)0; i <= (long long)30; i++) {
    pows[p] = true;
    p *= 2;
  }
}
bool check(long long len) {
  vector<vector<long long> > b;
  b.assign(len + 1, vector<long long>());
  if (has[1] < len) return false;
  vector<long long> odd;
  map<long long, long long> oddhas;
  long long p = 1;
  long long last = len;
  for (long long i = (long long)1; i <= (long long)31; i++) {
    last = min(has[p], last);
    for (long long j = (long long)1; j <= (long long)last; j++) {
      b[j].push_back(p);
    }
    oddhas[p] = has[p] - last;
    if (oddhas[p] > 0) odd.push_back(p);
    p *= 2;
  }
  for (long long i = (long long)0; i <= (long long)nums.size() - 1; i++) {
    long long nn = nums[i];
    if (pows[nn] == 0) {
      odd.push_back(nn);
      oddhas[nn] = has[nn];
    }
  }
  long long sum = 0;
  for (long long i = (long long)0; i <= (long long)odd.size() - 1; i++) {
    sum += oddhas[odd[i]];
  }
  if (sum > len) return false;
  sort((odd).begin(), (odd).end());
  reverse((odd).begin(), (odd).end());
  long long beg = 1;
  for (long long i = (long long)0; i <= (long long)odd.size() - 1; i++) {
    long long nun = odd[i];
    for (long long k = (long long)0; k <= (long long)oddhas[nun] - 1; k++) {
      long long la = b[beg++].back();
      if (nun > la * 2) {
        return false;
      }
    }
  }
  return true;
}
signed main() {
  readfile();
  pre();
  cin >> n;
  for (long long i = (long long)0; i <= (long long)n - 1; i++) {
    long long a;
    cin >> a;
    has[a]++;
    if (has[a] == 1) {
      nums.push_back(a);
    }
  }
  long long lo = 1;
  long long hi = has[1];
  long long iter = 32;
  while (iter--) {
    long long mid = (lo + hi) / 2;
    bool ok = check(mid);
    if (ok)
      lo = mid;
    else
      hi = mid;
  }
  long long mnlen = (long long)1e18;
  for (long long i = (long long)max(0LL, lo - 10); i <= (long long)hi + 10;
       i++) {
    if (check(i)) {
      mnlen = i;
      break;
    }
  }
  if (mnlen == (long long)1e18)
    cout << -1 << endl;
  else {
    for (long long i = (long long)mnlen; i <= (long long)has[1]; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
