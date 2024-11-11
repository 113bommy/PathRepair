#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
long long gcd(long long n, long long m) { return m ? gcd(m, n % m) : n; }
pair<int, int> ppi[1005];
vector<int> g[1005];
long long y, k, x, ans, d, b, c, t, n, m, s;
char str[1005];
int sum[1005];
long long a[1005];
bool cmp(int a, int b) { return a > b; }
int find(int x) {
  if (x != sum[x]) return sum[x] = find(sum[x]);
}
void search(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) sum[fy] = fx;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> x;
    if (x == 1) {
      cin >> m;
      a[m]++;
      cin >> m;
      a[m]++;
    } else {
      cin >> m;
      a[m]++;
    }
  }
  x = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == 0)
      x++, y++;
    else
      s += (x + 1) / 2, x = 0;
  }
  s += (x + 1) / 2;
  cout << s << ' ' << y;
  return 0;
}
