#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b) { return a > b; }
class Compare {
 public:
  bool operator()(int a, int b) { return a > b; }
};
int mod(int a, int b) { return ((a % b) + b) % b; }
int a[100009], n, suffix[100009];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  suffix[n - 1] = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (a[suffix[i + 1]] >= a[i])
      suffix[i] = suffix[i + 1];
    else
      suffix[i] = i;
  }
  for (int i = 0; i < n; i++) {
    if (suffix[i] == i)
      printf("0 ");
    else
      printf("%d ", a[suffix[i]] - a[i] + 1);
  }
  return 0;
}
