#include <bits/stdc++.h>
using namespace std;
struct laik {
  int id;
  int count;
  int step;
};
vector<laik> mass;
int fnd_val(int id, int step) {
  for (int i = 0; i < mass.size(); i++) {
    if (mass[i].id == id) {
      mass[i].step = step;
      mass[i].count++;
      return i;
    }
  }
  return -1;
}
int main() {
  int n;
  scanf("%d", &n);
  int x;
  int t = 0;
  int max = 0;
  int imax = -1;
  laik tlk;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    t = fnd_val(x, i + 1);
    if (t > 0) {
      if (mass[t].count > max) {
        max = mass[t].count;
        imax = t;
      }
    } else {
      tlk.id = x;
      tlk.count = 1;
      tlk.step = i + 1;
      mass.push_back(tlk);
      if (mass[mass.size() - 1].count > max) {
        max = mass[mass.size() - 1].count;
        imax = mass.size() - 1;
      }
    }
  }
  printf("%d", mass[imax].id);
  return 0;
}
