#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 20;
int n;
string a, b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> a >> b;
  std::vector<int> v;
  int t = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
    v.push_back((b[i] - 'a' + a[i] - 'a' + t) % 26);
    t = (b[i] - 'a' + a[i] - 'a' + t) / 26;
  }
  v[v.size() - 1] += 26;
  for (int i = (int)v.size() - 1; i >= 0; --i) {
    if (v[i] % 2 && i - 1 >= 0) v[i - 1] += 26;
    v[i] /= 2;
  }
  for (int i = (int)v.size() - 1; i >= 0; --i) printf("%c", v[i] + 'a');
  puts("");
  return 0;
}
