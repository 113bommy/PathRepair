#include <bits/stdc++.h>
using namespace std;
int counter[1001];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    int a[t];
    for (int j = 0; j < t; j++) {
      cin >> a[j];
      counter[a[j]]++;
    }
  }
  for (int i = 0; i < 1001; i++) {
    if (counter[i] >= n) cout << i << " ";
  }
  cout << endl;
  return 0;
}
