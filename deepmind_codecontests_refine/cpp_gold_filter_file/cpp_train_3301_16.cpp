#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  int n, min, g = 1;
  scanf("%d", &n);
  int a[100005] = {0};
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    a[i] = i + (n - 1 + tmp - i) / n * n;
    if (i == 0) min = a[i];
    if (a[i] < min) {
      min = a[i];
      g = i + 1;
    }
  }
  cout << g;
}
