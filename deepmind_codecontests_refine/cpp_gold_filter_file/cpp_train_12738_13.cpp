#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    cout << "-1";
    exit(0);
  }
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 1; i <= n; i++)
    if (a[i] == i) swap(a[i], a[i + 1]);
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
