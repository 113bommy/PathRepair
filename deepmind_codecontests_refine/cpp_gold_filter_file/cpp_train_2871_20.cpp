#include <bits/stdc++.h>
using namespace std;
int a[200001];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int x = n - 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (i >= n / 2) break;
    if (i % 2 != 0)
      continue;
    else
      swap(a[i], a[x]), x -= 2;
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  exit(0);
}
