#include <bits/stdc++.h>
using namespace std;
vector<int> num;
vector<int> result;
int main() {
  int n, t;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    num.push_back(t);
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (num[i] != num[i + 1]) {
      int cnt = 0;
      int j;
      for (j = i; j < n - 1; j++) {
        if (num[j] != num[j + 1])
          cnt++;
        else
          break;
      }
      ans = max(ans, cnt / 2);
      if (num[i] == num[j]) {
        for (int k = i; k < j; k++) result.push_back(num[i]);
      } else {
        for (int k = i; k <= j; k++) {
          if (k <= cnt / 2 + i)
            result.push_back(num[i]);
          else
            result.push_back(num[j]);
        }
      }
      i = j;
    } else
      result.push_back(num[i]);
  }
  result.push_back(num[n - 1]);
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    if (!i)
      printf("%d", result[i]);
    else
      printf(" %d", result[i]);
  }
  printf("\n");
  return 0;
}
