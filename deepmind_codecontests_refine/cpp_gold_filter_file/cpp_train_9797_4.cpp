#include <bits/stdc++.h>
using namespace std;
std::vector<int> v, es;
int n, a, b, s, x, mi = 1000000;
bool fl;
int main() {
  scanf("%d %d", &n, &b);
  if (!b) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << i << ' ';
    return 0;
  }
  if (n <= b) {
    cout << 1 << endl << 1;
    return 0;
  }
  for (int i = 1; i <= b + 1; i++) {
    x = 1;
    fl = 0;
    for (int j = i + b; j <= n; j += 2 * b + 1) {
      if (j == n) {
        x = 1;
        fl = 1;
        break;
      }
      ++x;
      if (j + 2 * b + 1 >= n && j + b + 1 <= n) {
        fl = 1;
        break;
      }
    }
    if (fl) {
      if (x < mi) {
        mi = x;
        s = i;
      }
    }
  }
  es.push_back(s);
  fl = 0;
  for (int i = s + 2 * b + 1; i <= n; i += 2 * b + 1) {
    es.push_back(i);
  }
  printf("%d\n", es.size());
  for (int i : es) printf("%d ", i);
}
