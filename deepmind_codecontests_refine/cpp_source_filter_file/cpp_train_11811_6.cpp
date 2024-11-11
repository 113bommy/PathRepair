#include <bits/stdc++.h>
using namespace std;
int main() {
  long long sm = 0;
  int n;
  cin >> n;
  int a[100001];
  for (int i = 1; i < n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    if (a[i] != i) {
      cout << i;
      break;
    }
}
