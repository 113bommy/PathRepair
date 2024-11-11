#include <bits/stdc++.h>
using namespace std;
struct intr {
  int a;
  int b;
};
int main() {
  int n, P1, P2, P3, T1, T2;
  vector<intr> v;
  int wTime = 0;
  cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
  for (int i = 0; i != n; i++) {
    intr tmp;
    cin >> tmp.a >> tmp.b;
    v.push_back(tmp);
  }
  wTime += (v[0].b - v[0].a) * P1;
  for (int i = 1; i < n; i++) {
    wTime += (v[i].b - v[i].a) * P1;
    if (v[i].a - v[i - 1].b >= T1 + T2) {
      wTime += (v[i].a - v[i - 1].b - T1 - T2) * P3 + T2 * P2 + T1 * P1;
    } else if (v[i].a - v[i - 1].b >= T1) {
      wTime += (v[i].a - v[i - 1].b - T1) * P2 + T1 * P1;
    }
    if (v[i].a - v[i - 1].b < T1) wTime += (v[i].a - v[i - 1].b) * P1;
  }
  cout << wTime;
  return 0;
}
