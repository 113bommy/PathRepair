#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int n, m;
string s, t;
char p[15], q[15];
map<string, string> M;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); ++i) {
    scanf("%s%s", p, q);
    s = p, t = q, M[t] = s;
  }
  for (int i = (1); i <= (m); ++i) {
    scanf("%s%s", p, q);
    t = q, t.erase(--t.end());
    printf("%s %s #%s\n", p, q, M[t].c_str());
  }
  return 0;
}
