#include <bits/stdc++.h>
using namespace std;
long long int root(long long int *init, long long int x) {
  long long int j = x;
  while (init[j] != j) {
    j = init[j];
  }
  return j;
}
void unio(long long int a, long long int b, long long int *init,
          long long int *l) {
  long long int x = root(init, a);
  long long int y = root(init, b);
  if (x != y) {
    if (l[x] >= l[y]) {
      l[x] += 1;
      init[y] = init[x];
    } else {
      l[y] += 1;
      init[x] = init[y];
    }
  }
}
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int l[n], init[n];
  for (long long int i = 1; i <= n; i++) {
    init[i] = i;
    l[i] = 1;
  }
  for (long long int i = 0; i < m; i++) {
    long long int x;
    cin >> x;
    for (long long int j = 0; j < x; j++) {
      long long int temp, st;
      cin >> temp;
      if (j == 0) {
        st = temp;
      }
      if (x > 1 && st != temp) unio(root(init, st), root(init, temp), init, l);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << l[root(init, i)] << " ";
  }
}
