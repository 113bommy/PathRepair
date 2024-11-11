#include <bits/stdc++.h>
using namespace std;
struct Day {
  int M_come;
  int M_leave;
  int F_come;
  int F_leave;
} Days[368];
int main() {
  int n;
  cin >> n;
  char gender;
  int c, l;
  for (int i = 0; i < n; ++i) {
    std::cin >> gender >> c >> l;
    if (gender == 'M') {
      Days[c].M_come++;
      Days[l + 1].M_leave++;
    } else {
      Days[c].F_come++;
      Days[l + 1].F_leave++;
    }
  }
  int male = 0;
  int female = 0;
  int max = 0;
  for (int i = 0; i < 367; ++i) {
    male += Days[i].M_come;
    male -= Days[i].M_leave;
    female += Days[i].F_come;
    female -= Days[i].F_leave;
    int day_max = male > female ? female : male;
    if (day_max > max) {
      max = day_max;
    }
  }
  std::cout << 2 * max;
  return 0;
}
