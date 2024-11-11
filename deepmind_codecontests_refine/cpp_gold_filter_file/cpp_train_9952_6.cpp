#include <bits/stdc++.h>
using namespace std;
int t[200][10];
int solve[10], opr[10];
int per, cnt;
double score(int ac) {
  if (32 * ac <= per)
    return 3000;
  else if (16 * ac <= per)
    return 2500;
  else if (8 * ac <= per)
    return 2000;
  else if (4 * ac <= per)
    return 1500;
  else if (2 * ac <= per)
    return 1000;
  else
    return 500;
}
double cal(int ac, double t) { return 1.0 * score(ac) * (1 - t / 250.0); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> per;
  for (int i = 0; i < per; i++)
    for (int j = 0; j < 5; j++) {
      cin >> t[i][j];
      if (t[i][j] != -1) solve[j]++;
    }
  double s1 = 0, s2 = 0;
  for (int i = 0; i < 5; i++) {
    if (t[0][i] != -1) s1 += cal(solve[i], t[0][i]);
    if (t[1][i] != -1) s2 += cal(solve[i], t[1][i]);
    if (t[0][i] != -1 && t[1][i] != -1 && (t[0][i] > t[1][i])) opr[i] = 1;
  }
  while (s1 <= s2) {
    s1 = 0, s2 = 0;
    cnt++, per++;
    for (int i = 0; i < 5; i++) {
      solve[i] += opr[i];
      if (t[0][i] != -1) s1 += cal(solve[i], t[0][i]);
      if (t[1][i] != -1) s2 += cal(solve[i], t[1][i]);
    }
    if (cnt == 4000) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << cnt << endl;
  return 0;
}
