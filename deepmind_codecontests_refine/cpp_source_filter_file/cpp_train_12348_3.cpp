#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  int n;
  scanf("%d ", &n);
  int tmp;
  for (int i = 0; i < 2 * n; ++i) {
    scanf("%d ", &tmp);
    a.push_back(tmp);
  }
  sort(a.begin(), a.end(), greater<int>());
  if (a[n - 1] <= a[n]) {
    printf("NO");
  } else {
    printf("YESs");
  }
  return 0;
}
