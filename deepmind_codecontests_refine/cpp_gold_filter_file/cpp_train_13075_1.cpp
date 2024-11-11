#include <bits/stdc++.h>
using namespace std;
int counter[1000] = {0};
int main() {
  string a, b;
  int ta, tb, maxpos = 0, maxtmp = 0, tmp_pos = 0;
  cin >> ta >> tb;
  cin >> a >> b;
  int pa = 0, pb = 0, ans = pb + ta - 1;
  if (ta == tb) {
    int ans = 0;
    for (int i = 0; i < ta; i++) {
      if (a[i] != b[i]) ans++;
    }
    cout << ans << endl;
    for (int i = 0; i < ta; i++) {
      if (a[i] != b[i]) cout << i + 1 << ' ';
      ;
    }
    return 0;
  }
  if (ta == 1) {
    int ans1 = 0;
    for (int i = 0; i < tb; i++) {
      if (a[0] == b[i]) ans1 = 1;
    }
    if (ans1 == 1) {
      cout << '0' << endl;
    } else {
      cout << '1' << endl << '1';
    }
    return 0;
  }
  while (ans <= tb - 1) {
    if (b[pb] == a[pa]) {
      counter[ans]++;
    }
    pb++;
    (pa++) % ta;
    if (pb == ans) {
      if (b[pb] == a[pa]) {
        counter[ans]++;
      }
      maxtmp = max(counter[ans], maxtmp);
      if (counter[ans] >= maxtmp) {
        maxpos = ans;
      }
      tmp_pos++;
      ans = tmp_pos + ta - 1;
      pb = tmp_pos;
      pa = 0;
    }
  }
  cout << ta - counter[maxpos] << endl;
  int start = maxpos - ta + 1;
  for (int i = 0; i < ta; i++) {
    if (a[i] != b[start]) cout << i + 1 << ' ';
    start++;
  }
  return 0;
}
