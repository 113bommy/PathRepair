#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool chmin(int& a, int b) { return b < a ? a = b, true : false; }
bool chmax(int& a, int b) { return b > a ? a = b, true : false; }
bool chmin(long long& a, long long b) { return b < a ? a = b, true : false; }
bool chmax(long long& a, long long b) { return b > a ? a = b, true : false; }
const int inf = 1e09 + 5e3;
const long long linf = 2e18 + 5e3;
const int mod = 1e9 + 7;
const int mxn = 1e6 + 30;
long long n;
vector<long long> out, taken, opposite;
vector<pair<long long, long long> > p;
void choose(int a, int c) {
  if (taken[a]++) return;
  if (c) {
    out.push_back(p[a].first);
    int go = opposite[p[a].second];
    choose(go, p[go].first % n == p[a].second % n);
  } else {
    out.push_back(p[a].second);
    int go = opposite[p[a].first];
    choose(go, p[go].first % n == p[a].first % n);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  if (n == 1) {
    cout << "Second" << endl;
    cout << 2 << endl;
    int q;
    cin >> q;
    exit(0);
  }
  p.assign(n, pair<long long, long long>(-1, -1));
  opposite.assign(3 * n, -1);
  int temp;
  long long sum = n * (n + 1) / 2;
  if (sum % (n)) {
    cout << "First" << endl;
    for (int i = 0; i < 2 * n; i++) {
      cout << (i % n) + 1 << ' ';
    }
    cout << endl;
    cin >> temp;
    exit(0);
  }
  cout << "Second" << endl;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> temp;
    temp--;
    if (~p[temp].first)
      p[temp].second = i;
    else
      p[temp].first = i;
    opposite[i] = temp;
  }
  for (int i = 1; i <= n; i++) {
    swap(opposite[i], opposite[i + n]);
  }
  int iteration = 0;
  do {
    int component = 0;
    out.clear();
    taken.assign(n, 0);
    for (int i = 0; i < n; i++) {
      if (taken[i]) continue;
      choose(i, rng() & 1);
    }
    iteration++;
  } while (accumulate((out).begin(), (out).end(), 0ll) % (2 * n) != 0);
  assert(out.size() == n);
  for (int i = 0; i < n; i++) {
    cout << out[i] << ' ';
  }
  cout << endl;
  cin >> temp;
  exit(0);
}
