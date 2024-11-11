#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const long double eps = 1e-9;
const int inf = 1e+9;
int n;
int a, b, c;
int mas[7] = {0, 1, 2, 3, 4, 5, 6};
string nm[7] = {"Anka",   "Chapay", "Cleo",       "Troll",
                "Dracul", "Snowy",  "Hexadecimal"};
pair<string, string> q[42];
int main() {
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> q[i].first >> q[i].second >> q[i].second;
  }
  cin >> a >> b >> c;
  int ans1 = 2 * inf;
  int ans2 = 0;
  do {
    for (int i = (0); i <= (7 - 3); ++i) {
      for (int j = (i + 1); j <= (7 - 2); ++j) {
        int p1 = a / (i + 1);
        int p2 = b / (j - i);
        int p3 = c / (6 - j);
        int minn = p1;
        minn = min(minn, p2);
        minn = min(minn, p3);
        int maxx = p1;
        maxx = max(maxx, p2);
        maxx = max(maxx, p3);
        if (ans1 >= maxx - minn) {
          if (ans1 > maxx - maxx) ans2 = 0;
          ans1 = maxx - minn;
          int temp = 0;
          for (int l = 0; l < (n); ++l) {
            int cc = 0;
            for (int k = (0); k <= (i); ++k)
              if (nm[mas[k]] == q[l].first || nm[mas[k]] == q[l].second) cc++;
            if (cc == 2) temp++;
          }
          for (int l = 0; l < (n); ++l) {
            int cc = 0;
            for (int k = (i + 1); k <= (j); ++k)
              if (nm[mas[k]] == q[l].first || nm[mas[k]] == q[l].second) cc++;
            if (cc == 2) temp++;
          }
          for (int l = 0; l < (n); ++l) {
            int cc = 0;
            for (int k = (j + 1); k <= (6); ++k)
              if (nm[mas[k]] == q[l].first || nm[mas[k]] == q[l].second) cc++;
            if (cc == 2) temp++;
          }
          ans2 = max(temp, ans2);
        }
      }
    }
  } while (next_permutation(mas, mas + 7));
  cout << ans1 << " " << ans2;
  return 0;
}
