#include <bits/stdc++.h>
using namespace std;
int N, M, K;
long long ret;
int s[100001];
int sum[100001];
int position[100001][25];
bool good[3000001];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", s + i);
    int k = s[i];
    int j = 0;
    while (j < 21) {
      if (k % 2)
        position[i][j] = i;
      else
        position[i][j] = position[i - 1][j];
      k /= 2;
      j++;
    }
  }
  int tmp[22], m;
  for (int i = N; i >= 1; i--) {
    m = 0;
    good[s[i]] = true;
    for (int j = 0; j < 21; j++) {
      tmp[m++] = position[i][j];
    }
    sort(tmp, tmp + m);
    for (int j = m - 1; j >= 0; j--) {
      s[i] |= s[tmp[j]];
      good[s[i]] = true;
    }
  }
  for (int i = 0; i <= 3000000; i++) {
    if (good[i]) {
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}
