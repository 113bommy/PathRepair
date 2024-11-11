#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
inline bool mina(A &first, B second) {
  return (first > second) ? (first = second, 1) : 0;
}
template <class A, class B>
inline bool maxa(A &first, B second) {
  return (first < second) ? (first = second, 1) : 0;
}
int powers[(200005)];
int num_can_solve[8];
void take(int start) {
  for (int i = start; i < 8; i++) {
    if (num_can_solve[i]) {
      num_can_solve[i]--;
      break;
    }
  }
}
int solve() {
  int temp[8];
  for (int(i) = 0; (i) < (8); ++(i)) temp[i] = num_can_solve[i];
  int ans = temp[1];
  ans += temp[2];
  temp[7] = max(0, temp[7] - temp[2]);
  temp[6] += temp[7];
  ans += temp[3];
  temp[6] = max(0, temp[6] - temp[3]);
  temp[5] += temp[6];
  ans += max(temp[4], (temp[4] + temp[5] + 1) / 2);
  return ans;
}
int main() {
  int N;
  scanf("%d", &N);
  for (int(i) = 0; (i) < (3); ++(i)) scanf("%d", &powers[i]);
  sort(powers, powers + 3);
  int a;
  for (int(i) = 0; (i) < (N); ++(i)) {
    scanf("%d", &a);
    int cnt = 0;
    for (int(p) = 0; (p) < (1 << 3); ++(p)) {
      int sum = 0;
      for (int(q) = 0; (q) < (3); ++(q)) {
        if (p & (1 << q)) sum += powers[q];
      }
      if (sum >= a) cnt++;
    }
    num_can_solve[cnt]++;
  }
  if (num_can_solve[0]) {
    printf("-1\n");
    return 0;
  }
  int ans = (0x3f3f3f3f);
  for (int(i) = 0; (i) < (N + 1); ++(i)) {
    mina(ans, i + solve());
    take(7);
    take(6);
    if (powers[0] + powers[1] > powers[2])
      take(5);
    else
      take(4);
  }
  printf("%d\n", ans);
  return 0;
}
