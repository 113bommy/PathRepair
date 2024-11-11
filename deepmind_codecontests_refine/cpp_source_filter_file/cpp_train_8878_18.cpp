#include <bits/stdc++.h>
using namespace std;
const int Max = 200050;
int a[Max], b[Max];
bool vis[Max];
vector<vector<pair<int, int> > > v(Max);
pair<int, int> p[Max];
map<int, bool> mp;
map<pair<int, int>, int> xy;
vector<pair<int, int> > vv;
int prime[10000005];
static bool arr_ay[10000005];
long long c, k = 1;
int main() {
  int a, b, t, x, num, num1, i;
  cin >> a >> b;
  for (i = a + 1; i < 100000; i++) {
    t = i;
    num = 0;
    num1 = 0;
    while (t) {
      x = t % 10;
      if (x == 4 || x == 7) num = num * 10 + x;
      t /= 10;
    }
    while (num) {
      num1 = num1 * 10 + num % 10;
      num /= 10;
    }
    if (num1 == b) break;
  }
  cout << i;
  return 0;
}
