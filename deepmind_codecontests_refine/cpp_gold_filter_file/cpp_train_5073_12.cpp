#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[110];
int odd_num[110];
int even_num[110];
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 0) {
      even_num[i] = even_num[i - 1] + 1;
      odd_num[i] = odd_num[i - 1];
    } else {
      even_num[i] = even_num[i - 1];
      odd_num[i] = odd_num[i - 1] + 1;
    }
  }
  vector<int> vec;
  for (i = 2; i < n; i += 2) {
    if (even_num[i] == odd_num[i] &&
        even_num[n] - even_num[i] == odd_num[n] - odd_num[i])
      vec.push_back(abs(a[i + 1] - a[i]));
  }
  sort(vec.begin(), vec.end());
  int sum = 0;
  j = 0;
  while (j < vec.size() && sum + vec[j] <= m) {
    sum += vec[j];
    j++;
  }
  printf("%d\n", j);
}
