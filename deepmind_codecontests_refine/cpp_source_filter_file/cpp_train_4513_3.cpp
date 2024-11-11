#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a, b;
bool is_sorted(void);
int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  int i, j;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0, j = 0; i < n && j < n; j++)
    if (a[i] == a[j]) i++;
  cout << n - i;
  return 0;
}
