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
    a[i] = i + (5 + tmp - i) / 6 * 6;
    if (i == 0) min = a[i];
    if (a[i] < min) {
      min = a[i];
      g = i + 1;
    }
  }
  cout << g;
}
