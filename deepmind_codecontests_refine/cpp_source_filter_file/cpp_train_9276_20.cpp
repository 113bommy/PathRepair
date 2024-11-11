#include <bits/stdc++.h>
using namespace std;
int counter[100];
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
  for (int i = 0; i < 100; i++) {
    if (counter[i] >= n) cout << i << " ";
  }
  cout << endl;
  return 0;
}
