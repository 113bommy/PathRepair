#include <bits/stdc++.h>
using namespace std;
struct st {
  int id, v;
};
struct st1 {
  int id, v, m;
};
st s1[100010], s2[100010];
vector<st1> w1;
string a1, a2;
bool cmp(st1 a, st1 b) { return a.v < b.v; }
int main() {
  int n;
  while (cin >> n) {
    a1 = "", a2 = "";
    int x, y;
    for (int i = 0; i < n; ++i) {
      a1 += '0';
      a2 += '0';
      scanf("%d %d", &x, &y);
      st1 val;
      val.v = x;
      val.id = i;
      val.m = 0;
      w1.push_back(val);
      val.v = y;
      val.id = i;
      val.m = 1;
      w1.push_back(val);
    }
    sort((w1).begin(), (w1).end(), cmp);
    for (int i = 0; i < n / 2; ++i) a1[i] = a2[i] = '1';
    for (int i = 0; i < n; ++i)
      if (w1[i].m)
        a1[w1[i].id] = '1';
      else
        a2[w1[i].id] = '1';
    for (int i = n; i < 2 * n; i++) {
      if (w1[i].v == w1[n - 1].v) {
        if (w1[i].m)
          a1[w1[i].id] = '1';
        else
          a2[w1[i].id] = '1';
      } else
        break;
    }
    w1.clear();
    cout << a1 << endl << a2 << endl;
  }
  return 0;
}
