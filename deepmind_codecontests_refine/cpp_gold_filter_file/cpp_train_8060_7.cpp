#include <bits/stdc++.h>
using namespace std;
bool compare(const int& a, const int& b) { return a > b; }
int main() {
  int a[101];
  int i = 0;
  int n, k;
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, compare);
  cout << a[k - 1] << endl;
}
