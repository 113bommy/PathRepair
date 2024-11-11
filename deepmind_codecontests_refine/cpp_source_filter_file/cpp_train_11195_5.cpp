#include <bits/stdc++.h>
using namespace std;
long long a_x, a_y, b_x, b_y, t_x, t_y;
long long n;
double best_to_a = 1500000000, sbest_to_a = 1500000000, best_to_b = 1500000000,
       sbest_to_b = 1500000000;
int ba_ind, sba_ind, bb_ind, sbb_ind;
int main() {
  cout << setprecision(14);
  cin >> a_x >> a_y >> b_x >> b_y >> t_x >> t_y;
  cin >> n;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 1) {
    long long x, y;
    cin >> x >> y;
    double dist_bin = sqrt((x - t_x) * (x - t_x) + (y - t_y) * (y - t_y));
    double dist_a = sqrt((x - a_x) * (x - a_x) + (y - a_y) * (y - a_y));
    double dist_b = sqrt((x - b_x) * (x - b_x) + (y - b_y) * (y - b_y));
    cout << dist_bin + min(dist_a, dist_b) << endl;
    return 0;
  }
  double sum_dist = 0.0;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    double dist_bin = sqrt((x - t_x) * (x - t_x) + (y - t_y) * (y - t_y));
    sum_dist += 2 * dist_bin;
    double dist_a, dist_b;
    dist_a = sqrt((x - a_x) * (x - a_x) + (y - a_y) * (y - a_y)) - dist_bin;
    dist_b = sqrt((x - b_x) * (x - b_x) + (y - b_y) * (y - b_y)) - dist_bin;
    if (dist_a < best_to_a) {
      sbest_to_a = best_to_a;
      sba_ind = ba_ind;
      best_to_a = dist_a;
      ba_ind = i;
    } else if (dist_a < sbest_to_a) {
      sbest_to_a = dist_a;
      sba_ind = i;
    }
    if (dist_b < best_to_b) {
      sbest_to_b = best_to_b;
      sbb_ind = bb_ind;
      best_to_b = dist_b;
      bb_ind = i;
    } else if (dist_b < sbest_to_b) {
      sbest_to_b = dist_b;
      sbb_ind = i;
    }
  }
  if (best_to_a > 0 || best_to_b > 0) {
    cout << sum_dist + min(best_to_b, best_to_a) << endl;
    return 0;
  }
  if (ba_ind == bb_ind) {
    if (sbest_to_a > 0 && sbest_to_b > 0) {
      cout << sum_dist + min(best_to_a, best_to_b) << endl;
      return 0;
    }
    cout << sum_dist + min(best_to_a + sbest_to_b, sbest_to_a + best_to_b)
         << endl;
  } else {
    cout << sum_dist + best_to_a + best_to_b << endl;
  }
}
