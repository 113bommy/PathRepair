#include <bits/stdc++.h>
using namespace std;
long long N = 2e5 + 5;
std::vector<int> v;
const int maxn = 1e5 + 5;
int t[maxn], l[maxn];
bool isVowel(char a) {
  if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
  return false;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
long long INF = 1e9;
int n;
vector<int> ans;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    if (i % n == 0) reverse(s.begin(), s.begin() + i);
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  solve();
}
