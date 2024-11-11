#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t, t + n);
  for (int i = 0; i < n; i++) {
    cout << t[i] << " ";
  }
}
