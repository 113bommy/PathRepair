#include <bits/stdc++.h>
using namespace std;
struct s {
  unsigned h, a, d;
};
bool y_wins(s y, s m) {
  int decrease_m = y.a - m.d;
  int decrease_y = m.a - y.d;
  unsigned t_m;
  if (decrease_m <= 0)
    t_m = UINT_MAX;
  else
    t_m = (m.h + decrease_m - 1) / decrease_m;
  unsigned t_y;
  if (decrease_y <= 0)
    t_y = UINT_MAX;
  else
    t_y = (y.h + decrease_y - 1) / decrease_y;
  return t_y > t_m;
}
int main(void) {
  s y, m;
  unsigned h, a, d;
  scanf("%u %u %u\n", &y.h, &y.a, &y.d);
  scanf("%u %u %u\n", &m.h, &m.a, &m.d);
  scanf("%u %u %u\n", &h, &a, &d);
  unsigned best_cost = UINT_MAX;
  for (unsigned j = 0; j <= 600; ++j) {
    int decrease_m = y.a + j - m.d;
    if (decrease_m <= 0) continue;
    for (unsigned i = 0; i <= 600; ++i) {
      for (unsigned k = 0; k <= 600; ++k) {
        unsigned cost = i * h + j * a + k * d;
        if (best_cost <= cost) continue;
        if (y_wins({y.h + i, y.a + j, y.d + k}, m)) {
          best_cost = cost;
        }
      }
    }
  }
  printf("%u", best_cost);
}
