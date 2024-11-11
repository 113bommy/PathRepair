#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  int n, sum = 0, ans = 0;
  char c;
  scanf("%d", &n);
  getchar();
  while (c != '\n') {
    c = getchar();
    if ((!sum) && c == ' ') continue;
    sum++;
    if (sum > n) {
      printf("Impossible\n");
      return 0;
    }
    if (c == '.' || c == '?' || c == '!') {
      a.push_back(sum);
      sum = 0;
    }
  }
  sum = 0;
  for (int i = 0; i < a.size(); i++) {
    if (sum + a[i] + 1 <= n)
      sum = sum + a[i] + 1;
    else {
      sum = a[i];
      ans++;
    }
  }
  if (sum) ans++;
  printf("%d\n", ans + 1);
  return 0;
}
