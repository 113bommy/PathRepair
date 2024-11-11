#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int a[MAX];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << a[n - k];
}
