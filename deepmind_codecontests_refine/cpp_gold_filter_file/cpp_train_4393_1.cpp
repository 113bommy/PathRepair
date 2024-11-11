#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
char x;
int main() {
  a.push_back(0);
  scanf("%d %d\n", &n, &k);
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a.push_back((int)x - 48);
  }
  ++n;
  for (int i = 2; i < n && k; ++i)
    if (a[i] == 7 && a[i - 1] == 4) {
      if (a[i - 2] == 4 && (i - 1) % 2 == 0) {
        if (k % 2 != 0) a[i - 1] = 7;
        break;
      } else {
        if ((i - 1) % 2 == 0) {
          a[i] = a[i - 1] = 7;
          --k;
        } else {
          a[i] = a[i - 1] = 4;
          --k;
        }
        --i;
      }
    }
  for (int i = 0; i < n - 1; ++i) printf("%d", a[i + 1]);
  return 0;
}
