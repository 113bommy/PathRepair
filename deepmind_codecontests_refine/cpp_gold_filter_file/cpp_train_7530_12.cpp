#include <bits/stdc++.h>
using namespace std;
struct elem {
  int pos;
  char lit;
};
bool comp(elem e1, elem e2) {
  if (e1.lit > e2.lit)
    return 1;
  else if (e1.lit < e2.lit)
    return 0;
  else
    return e1.pos < e2.pos;
}
elem v[100007];
int main() {
  char sir[100007];
  int lg, i;
  cin.get(sir, 1000000, '\n');
  cin.get();
  lg = strlen(sir);
  for (i = 0; i < lg; i++) v[i].pos = i, v[i].lit = sir[i];
  sort(v, v + lg, comp);
  int last = -1;
  for (i = 0; i < lg; i++)
    if (v[i].pos > last) {
      cout << v[i].lit;
      last = v[i].pos;
    }
  cout << '\n';
  return 0;
}
