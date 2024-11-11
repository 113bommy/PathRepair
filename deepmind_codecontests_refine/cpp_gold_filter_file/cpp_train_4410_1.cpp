#include <bits/stdc++.h>
using namespace std;
int N;
string a, b;
double S1, S2, nr[30][200100], s[30][200100];
int main() {
  scanf("%d", &N);
  cin >> a >> b;
  for (int i = 1; i <= N; ++i) {
    S2 += 1LL * i * i;
    for (int j = 0; j < 26; ++j) {
      if (b[i - 1] == j + 'A') {
        s[j][i] = s[j][i - 1] + i;
        nr[j][i] = nr[j][i - 1] + 1;
      } else {
        s[j][i] = s[j][i - 1];
        nr[j][i] = nr[j][i - 1];
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    int c = a[i - 1] - 'A';
    S1 += 1LL * (N - i + 1) * s[c][i];
    S1 += 1LL * (N + 1) * i * (nr[c][N] - nr[c][i]);
    S1 -= 1LL * i * (s[c][N] - s[c][i]);
  }
  printf("%.12lf", 1.0 * S1 / S2);
  return 0;
}
