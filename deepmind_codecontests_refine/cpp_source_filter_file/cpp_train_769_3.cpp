#include <bits/stdc++.h>
using namespace std;
void Conduct(const int &n) {
  vector<int> value(n);
  for (int i = 0; i < n; ++i) scanf("%d", &value[i]);
  sort(value.begin(), value.end());
  int result = n;
  for (int i = 0, j = n / 2 + 1; i < n / 2 + 1; ++i) {
    while (j < n && value[j] < value[i] * 2) ++j;
    if (j < n) {
      result--;
      j++;
    }
  }
  printf("%d\n", result);
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) Conduct(n);
  return 0;
}
