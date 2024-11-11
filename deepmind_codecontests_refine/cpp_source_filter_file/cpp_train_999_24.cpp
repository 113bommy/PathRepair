#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int data[N];
int main() {
  int n;
  scanf("%d", &n);
  int cc = 0, sum = 0;
  for (int i = (1); i < (n + 1); ++i) {
    scanf("%d", &data[i]);
    sum += data[i] / 1000;
    if (data[i] = 1000) cc++;
  }
  int tmp = 10 * sum / 11;
  if (sum <= 11) tmp = sum - data[n] / 1000;
  if (!cc && (tmp & 1)) tmp--;
  printf("%d\n", sum * 1000 - tmp * 100);
  return 0;
}
