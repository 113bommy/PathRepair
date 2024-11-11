#include <bits/stdc++.h>
using namespace std;
map<string, int> mm;
map<int, string> mm2;
int points[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
struct node {
  int a[1010];
  int p;
  int pos;
};
node per[2000];
int ca, n;
string s;
int id = 0;
bool cmp1(node a, node b) {
  if (a.p != b.p) return a.p > b.p;
  for (int i = 0; i < id; i++)
    if (a.a[i] != b.a[i]) return a.a[i] > b.a[i];
  return false;
}
bool cmp2(node a, node b) {
  if (a.a[0] != b.a[0]) return a.a[0] > b.a[0];
  if (a.p != b.p) return a.p > b.p;
  for (int i = 1; i < id; i++)
    if (a.a[i] != b.a[i]) return a.a[i] > b.a[i];
  return false;
}
int main() {
  cin >> ca;
  mm.clear();
  mm2.clear();
  while (ca--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s;
      if (mm.find(s) == mm.end()) {
        mm[s] = id;
        mm2[id] = s;
        per[id].pos = id;
        per[id].p = 0;
        id++;
      }
      per[mm[s]].a[i]++;
      if (i < 10) per[mm[s]].p += points[i];
    }
  }
  sort(per, per + id, cmp1);
  cout << mm2[per[0].pos] << endl;
  sort(per, per + id, cmp2);
  cout << mm2[per[0].pos] << endl;
  return 0;
}
