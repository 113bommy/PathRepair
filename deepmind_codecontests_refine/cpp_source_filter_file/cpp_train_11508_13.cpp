#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int N, D, H;
  scanf("%d%d%d", &N, &D, &H);
  if (D > 2 * H) {
    cout << -1 << endl;
    exit(0);
  }
  if (H > D) {
    cout << -1 << endl;
    exit(0);
  }
  if (H == 1 && D > 2) {
    cout << -1 << endl;
    exit(0);
  }
  if (H == 1 && D == 1) {
    cout << -1 << endl;
    exit(0);
  }
  for (int i = 1; i <= H; i++) {
    printf("%d %d\n", i, i + 1);
  }
  if (D == H) {
    for (int i = H + 2; i <= N; i++) printf("%d %d\n", H, i);
  } else {
    printf("%d %d\n", 1, H + 2);
    for (int i = H + 2; i <= D; i++) printf("%d %d\n", i, i + 1);
    for (int i = D + 2; i <= N; i++) {
      printf("%d %d\n", 1, i);
    }
  }
};
