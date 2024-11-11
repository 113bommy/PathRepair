#include <bits/stdc++.h>
using namespace std;
const long long nmax = 2 * 1e5 + 42, inf = 1e9 + 1e6;
long long n, k;
string inp[nmax];
pair<long long, long long> seen[nmax];
long long outp[nmax];
long long take(string s) {
  long long mult = 1;
  long long ret = 0;
  for (auto k : s)
    if (k == '-')
      mult = -1;
    else
      ret = ret * 10 + (k - '0');
  return ret * mult;
}
void make(long long i) {
  if (seen[i % k].first >= 0 && outp[i] >= 0) {
    long long now = seen[i % k].first;
    for (long long j = seen[i % k].second + k; j < i; j = j + k) {
      now++;
      outp[j] = now;
    }
    for (long long j = seen[i % k].second + k; j < i && j < n; j = j + k)
      if (j - k >= 0 && outp[j - k] >= outp[j]) assert(0 == 1);
    return;
  }
  if (seen[i % k].first <= 0 && outp[i] <= 0) {
    long long now = outp[i];
    for (long long j = i - k; j > seen[i % k].second; j = j - k) {
      now--;
      outp[j] = now;
    }
    for (long long j = seen[i % k].second + k; j < i && j < n; j = j + k)
      if (j - k >= 0 && outp[j - k] >= outp[j]) {
        cout << ":(" << endl;
        exit(0);
      }
    return;
  }
  long long d = (i - seen[i % k].second) / k - 1;
  if (d == 0) return;
  deque<long long> help = {0};
  for (long long v = 1; help.size() < d; v++) {
    if (seen[i % k].first < -v) help.push_front(-v);
    if (help.size() == d) break;
    if (outp[i] > v) help.push_back(v);
  }
  for (long long p = seen[i % k].second + k; p < i; p = p + k) {
    if (help.size() == 0) {
      cout << "y" << endl;
      exit(0);
    }
    outp[p] = help.front();
    help.pop_front();
  }
  if (help.size()) {
    cout << "qqq" << endl;
    exit(0);
  }
  for (long long j = seen[i % k].second + k; j < i && j < n; j = j + k)
    if (j - k >= 0 && outp[j - k] >= outp[j]) {
      cout << ":(" << endl;
      exit(0);
    }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> inp[i];
  for (long long i = 0; i < k; i++) seen[i] = {-(inf), i - k};
  for (long long i = 0; i < n; i++)
    if (inp[i] != "?") {
      outp[i] = take(inp[i]);
      if (seen[i % k].first + (i - seen[i % k].second) / k <= outp[i]) {
        make(i);
      } else {
        cout << "Incorrect sequence" << endl;
        return 0;
      }
      seen[i % k] = {outp[i], i};
    }
  for (long long i = n; i - k + 1 <= n; i++)
    if (seen[i % k].second + k != i) {
      outp[i] = inf;
      make(i);
    }
  for (long long i = 0; i < n; i++) cout << outp[i] << " ";
  cout << endl;
  return 0;
}
