#include <bits/stdc++.h>
using namespace std;
struct thr {
  int a, b, c, no;
};
int n, l, r;
vector<thr> v;
bool t1(thr a, thr b) { return a.c > b.c; }
bool t2(thr a, thr b) { return a.no < b.no; }
int main() {
  cin >> n >> l >> r;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].a;
    v[i].no = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i].c;
  }
  sort(v.begin(), v.end(), t1);
  v[0].b = r;
  for (int i = 1; i < n; i++) {
    v[i].b = v[i - 1].b - v[i - 1].a + v[i].a - 1;
    if ((v[i - 1].b - v[i - 1].a + v[i].a - 1) < l) {
      cout << "-1" << endl;
      return 0;
    }
  }
  sort(v.begin(), v.end(), t2);
  for (int i = 0; i < n; i++) {
    cout << v[i].b << " ";
  }
  cout << endl;
  return 0;
}
