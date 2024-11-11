#include <bits/stdc++.h>
using namespace std;
const long long int y = 1000;
const long long int INF = y * y * y * y * y * y;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int n0 = 0, n1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0)
      n0 = i;
    else
      n1 = i;
  }
  cout << min(n1, n0) + 1;
}
