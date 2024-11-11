#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 6;
const long long inf = 1e15;
long long n;
typedef struct node {
  long long x, y, ind;
} node;
node a[N];
bool cmpfunc(node &a, node &b) {
  return ((a.x < b.x) || (a.x == b.x && a.y > b.y));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("inp.txt", "r")) {
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
  }
  cin >> n;
  long long i;
  for (i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].ind = i;
  }
  sort(a + 1, a + n + 1, cmpfunc);
  long long l = 1;
  bool poss = false;
  for (i = 2; i <= n; i++) {
    if (a[i].y <= a[l].y) {
      poss = true;
      cout << a[i].ind << " " << a[l].ind;
      break;
    } else
      l = i;
  }
  if (!poss) cout << "-1 -1";
  return 0;
}
