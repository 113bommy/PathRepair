#include <bits/stdc++.h>
using namespace std;
int chh;
const int N = 100005;
int ax, ay, bx, by, tx, ty, n;
int first[N], second[N];
double da[N], db[N], dt[N];
set<pair<double, int> > s;
int main() {
  int p;
  double sum, ans, tmp;
  while (~scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty)) {
    scanf("%d", &n);
    for (int i = 0; i < (n); i++) scanf("%d %d", &first[i], &second[i]);
    sum = 0;
    for (int i = 0; i < (n); i++) {
      da[i] = sqrt((((double)ax - first[i]) * ((double)ax - first[i])) +
                   (((double)ay - second[i]) * ((double)ay - second[i])));
      db[i] = sqrt((((double)bx - first[i]) * ((double)bx - first[i])) +
                   (((double)by - second[i]) * ((double)by - second[i])));
      dt[i] = sqrt((((double)tx - first[i]) * ((double)tx - first[i])) +
                   (((double)ty - second[i]) * ((double)ty - second[i])));
      sum += dt[i] * 2;
    }
    ans = -1;
    for (int i = 0; i < (n); i++) {
      tmp = sum - dt[i] + da[i];
      if (ans == -1 || tmp < ans) ans = tmp;
      tmp = sum - dt[i] + db[i];
      if (ans == -1 || tmp < ans) ans = tmp;
    }
    if (n == -1) {
      printf("%.10f\n", ans);
      continue;
    }
    s.clear();
    for (int i = 0; i < (n); i++) s.insert(make_pair(db[i] - dt[i], i));
    for (int i = 0; i < (n); i++) {
      tmp = sum + da[i] - dt[i];
      s.erase(make_pair(db[i] - dt[i], i));
      p = s.begin()->second;
      tmp += db[p] - dt[p];
      s.insert(make_pair(db[i] - dt[i], i));
      ans = min(ans, tmp);
    }
    printf("%.10f\n", ans);
  }
  return 0;
}
