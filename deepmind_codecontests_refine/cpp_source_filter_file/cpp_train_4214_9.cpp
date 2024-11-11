#include <bits/stdc++.h>
using namespace std;
int n, x[4];
void find0() { x[0] = 1; }
void find1() { x[1] = 2 * x[0]; }
void find2() {
  vector<int> v;
  v.push_back(x[0]);
  v.push_back(x[1]);
  sort(v.begin(), v.end());
  x[2] = 4 * x[0] - x[1];
}
bool check() {
  vector<int> v;
  v.push_back(x[0]);
  v.push_back(x[1]);
  v.push_back(x[2]);
  v.push_back(x[3]);
  sort(v.begin(), v.end());
  int sum;
  if (v[0] <= 0 || v[1] <= 0 || v[2] <= 0 || v[3] <= 0) return 0;
  sum = v[0] + v[1] + v[2] + v[3];
  if (sum / 4 * 4 != sum) return 0;
  sum = v[1] + v[2];
  if (sum / 2 * 2 != sum) return 0;
  if ((v[0] + v[1] + v[2] + v[3]) / 4 != (v[1] + v[2]) / 2 ||
      (v[1] + v[2]) / 2 != v[3] - v[0])
    return 0;
  return 1;
}
void find3() {
  vector<int> v;
  v.push_back(x[0]);
  v.push_back(x[1]);
  v.push_back(x[2]);
  sort(v.begin(), v.end());
  x[3] = x[0] + x[1] - x[2];
  if (check()) return;
  x[3] = x[0] + x[2] - x[1];
  if (check()) return;
  x[3] = x[1] + x[2] - x[0];
  if (check()) return;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  switch (n) {
    case 0:
      find0();
    case 1:
      find1();
    case 2:
      find2();
    case 3:
      find3();
    case 4:
      break;
  }
  if (check()) {
    printf("YES");
    for (int i = n; i < 4; ++i) {
      printf("\n%d", x[i]);
    }
  } else {
    printf("NO");
  }
  return 0;
}
