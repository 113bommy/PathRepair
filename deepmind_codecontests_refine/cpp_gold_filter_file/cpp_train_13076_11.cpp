#include <bits/stdc++.h>
using namespace std;
int findNumEq(string a[], int i, int n) {
  int count = 0;
  for (int j = 0; j < n; j++) {
    if (a[j].at(i) == '1') {
      count++;
    }
  }
  return count;
}
int main() {
  int n;
  cin >> n;
  string a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int maxR = 0;
  for (int i = 0; i < 7; i++) {
    int k = findNumEq(a, i, n);
    maxR = max(maxR, k);
  }
  cout << maxR;
  return 0;
}
