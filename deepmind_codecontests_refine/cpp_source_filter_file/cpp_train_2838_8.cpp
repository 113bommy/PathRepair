#include <bits/stdc++.h>
using namespace std;
long long mx = -1e9, mn = 1e9 + 5;
long long T, n, m, k, ans, a[200005], b, h, c, d, l, r, sum, mid, coin, cnt,
    pos, number, x, y, z, x2, y2;
vector<string> v, v1;
map<long long, long long> mp, mm;
map<long long, long long>::iterator it;
pair<long long, long long> p;
queue<long long> q;
priority_queue<long long> pq;
string s;
char ch[10][10];
bool check[10][10];
bool used[200005];
void solve() {
  cin >> x >> y >> z;
  if (x == y && x == z) {
    cout << "YES\n";
    cout << x << " " << x << " " << x << endl;
    return;
  }
  if (x == y && x > z) {
    cout << "YES\n";
    cout << x << " " << z << " " << 1 << "\n";
    return;
  }
  if (x == z && x > y) {
    cout << "YES\n";
    cout << y << " " << x << " " << 1 << "\n";
    return;
  }
  if (y == z && y > x) {
    cout << "YES\n";
    cout << x << " " << 1 << " " << x << "\n";
    return;
  }
  cout << "NO\n";
}
int main() {
  scanf("%lld", &T);
  while (T--) {
    solve();
  }
}
