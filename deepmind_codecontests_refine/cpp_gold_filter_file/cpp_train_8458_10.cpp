#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long infl = 1LL << 60;
char buf[1000000];
string nextLine() {
  scanf("%[^\n]", buf);
  scanf("%*c");
  return string(buf);
}
string next() {
  scanf("%s", buf);
  return string(buf);
}
int nextInt() {
  int tmp;
  scanf("%d", &tmp);
  return tmp;
}
const int MAXN = 100100;
long long ar[MAXN];
long long sum[MAXN];
long long cost(int x, int num) {
  long long s = sum[x] - sum[x - num];
  return num * ar[x] - s;
}
void solve() {
  long long n, k, cnt = 0, anss = 1e9 + 10, a, b;
  cin >> n;
  vector<long long> v(2 * n);
  for (auto &i : v) {
    cin >> i;
  }
  map<long long, long long> make_pair;
  for (auto x : v) {
    make_pair[x]++;
  }
  for (long long i = 0; i < 2 * n; i++) {
    if (make_pair[v[i]]) {
      cout << v[i] << " ";
      make_pair[v[i]] = 0;
    }
  }
  cout << endl;
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
