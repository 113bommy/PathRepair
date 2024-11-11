#include <bits/stdc++.h>
using namespace std;
int a[10000];
int n, b;
int mn;
int main() {
  mn = 1;
  cin >> n >> b;
  mn = 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      mn = max(mn, (b / a[j]) * a[i] + b % a[j]);
    }
  }
  cout << mn << endl;
  return 0;
}
