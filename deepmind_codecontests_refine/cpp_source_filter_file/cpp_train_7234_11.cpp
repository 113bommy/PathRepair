#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
int L[(100000 + 9)], R[(100000 + 9)], H[(100000 + 9)];
int n;
int main() {
  read_file();
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d", &H[i]);
    L[0] = 0, R[n - 1] = 0;
    for (int i = 1; i < n; i++) L[i] = min(L[i - 1] + 1, H[i]);
    for (int i = n - 2; i >= 0; i--) R[i] = min(R[i + 1] + 1, H[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, min(L[i], R[i]));
    printf("%d\n", ans);
  }
}
