#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, k;
  while (~scanf("%d %d", &n, &k)) {
    bool flag = true;
    int twoSeats = 2 * n;
    int fourSeats = n;
    int oneSeats = 0;
    int cntSeats[3];
    memset(cntSeats, 0, sizeof(cntSeats));
    int tmp;
    for (int i = 0; i < k; ++i) {
      scanf("%d", &tmp);
      while (tmp >= 3) {
        if (fourSeats > 0) {
          tmp -= 4;
          --fourSeats;
        } else if (twoSeats > 0) {
          tmp -= 2;
          --twoSeats;
        } else {
          flag = false;
        }
      }
      if (tmp > 0) ++cntSeats[tmp];
    }
    while (cntSeats[2]) {
      if (twoSeats > 0) {
        --cntSeats[2];
        --twoSeats;
      } else if (fourSeats > 0) {
        --cntSeats[2];
        --fourSeats;
        ++oneSeats;
      } else {
        --cntSeats[2];
        cntSeats[1] += 2;
      }
    }
    if (cntSeats[1] > oneSeats + twoSeats + fourSeats * 2) {
      flag = false;
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
