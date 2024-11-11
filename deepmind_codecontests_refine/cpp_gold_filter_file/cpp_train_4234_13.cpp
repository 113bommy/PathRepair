#include <bits/stdc++.h>
using namespace std;
struct point {
  int x;
  int y;
};
struct vec {
  int x;
  int y;
};
point r_array[12], b_array[12];
int root[12]{}, ocupied[12]{};
int r, b;
double cross(point a, point b, point c) {
  vec v1 = {c.x - a.x, c.y - a.y};
  vec v2 = {b.x - a.x, b.y - a.y};
  return (v1.x * v2.y - v1.y * v2.x);
}
bool r_check(int r1_index, int b1_index, int r2_index, int b2_index) {
  point r1_cor = r_array[r1_index];
  point r2_cor = r_array[r2_index];
  point b1_cor = b_array[b1_index];
  point b2_cor = b_array[b2_index];
  double kq_r1 = cross(r1_cor, r2_cor, b2_cor);
  double kq_b1 = cross(b1_cor, r2_cor, b2_cor);
  double kq_r2 = cross(r2_cor, r1_cor, b1_cor);
  double kq_b2 = cross(b2_cor, r1_cor, b1_cor);
  if (kq_r1 * kq_b1 > 0) return 0;
  if (kq_r2 * kq_b2 > 0) return 0;
  return 1;
}
bool check() {
  bool kq = 1;
  for (int i = 1; i < r; i++)
    for (int j = i + 1; j <= r; j++) {
      kq = min(kq, r_check(i, root[i], j, root[j]));
      if (kq == 0) return 0;
    }
  return kq;
}
bool sinh(int r_pos) {
  if (r_pos > r) {
    return check();
  }
  for (int i = 1; i <= b; i++) {
    if (ocupied[i]) continue;
    ocupied[i] = 1;
    root[r_pos] = i;
    bool kq = sinh(r_pos + 1);
    ocupied[i] = 0;
    if (kq) return kq;
  }
}
int main() {
  cin >> r >> b;
  for (int i = 1; i <= r; i++) cin >> r_array[i].x >> r_array[i].y;
  for (int i = 1; i <= b; i++) cin >> b_array[i].x >> b_array[i].y;
  if (r != b) {
    cout << "No";
    return 0;
  }
  bool kq = sinh(1);
  if (kq)
    puts("Yes");
  else
    puts("No");
}
