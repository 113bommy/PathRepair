#include <bits/stdc++.h>
using namespace std;
void sep(string SS = "BLOCK") {
  cout << "-------------" << SS << "-----------------\n";
}
template <typename t>
void pr(t a) {
  cout << a << endl;
}
template <typename t>
void prs(t a) {
  cout << a << " ";
}
template <typename T>
void debugv(vector<T> arr) {
  for (auto t : arr) cout << t << " ";
  cout << "\n";
}
template <typename T>
void debugarr(T arr, int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "\n";
}
template <typename T>
void chmax(T& a, T b) {
  if (a < b) a = b;
}
template <typename T>
void chmin(T& a, T b) {
  if (a > b) a = b;
}
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
const int maxn = 4e6 + 100;
const long long INF = 1e18;
long long a[maxn], n, m, t, k, q;
unordered_map<long long, long long> u;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long c = n / 2;
    while (c > 0 && a[c - 1] == a[c]) --c;
    if (c == 0) {
      prs(0);
      prs(0);
      pr(0);
      continue;
    }
    long long g = 1;
    while (g < c && a[g - 1] == a[g]) ++g;
    long long s = 1 + g;
    while (g + s < c && a[g + s - 1] == a[g + 1]) ++s;
    long long b = c - g - s;
    if (b > g) {
      prs(g);
      prs(s);
      pr(b);
    } else {
      prs(0);
      prs(0);
      pr(0);
    }
  }
}
