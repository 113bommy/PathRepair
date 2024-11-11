#include <bits/stdc++.h>
using namespace std;
int a[300010];
int vi[300010] = {0};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  if (n == 1) {
    cout << "1 1\n";
    return 0;
  }
  cout << "1 ";
  int ans = 0, pos = n;
  for (int i = 1; i <= n - 1; i++) {
    vi[a[i]] = 1;
    ans++;
    while (vi[pos]) {
      pos--;
    }
    cout << (ans - (n - pos) + 1) << " ";
  }
  cout << "1\n";
  return 0;
}
