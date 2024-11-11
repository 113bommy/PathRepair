#include <bits/stdc++.h>
using namespace std;
int M[20], R[20];
int main() {
  int n;
  int day, cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> M[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> R[i];
  }
  for (day = 0; day < 30; day++) {
    for (int i = 1; i <= n; i++)
      if (day % M[i] == R[i]) {
        cnt++;
        break;
      }
  }
  printf("%.9lf\n", (double)cnt / (double)(day));
  return 0;
}
