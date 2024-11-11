#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        cout << j << " " << j + 1 << endl;
      }
    }
  }
}
