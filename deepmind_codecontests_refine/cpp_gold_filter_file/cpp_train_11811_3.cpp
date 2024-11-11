#include <bits/stdc++.h>
using namespace std;
int main() {
  long long sm = 0;
  int n;
  cin >> n;
  int a[1000001];
  for (int i = 1; i < n; i++) cin >> a[i];
  sort(a + 1, a + n);
  for (int i = 1; i <= n; i++)
    if (a[i] != i) {
      cout << i;
      break;
    }
}
