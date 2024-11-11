#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int n1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 100) {
      n1++;
    }
  }
  int n2 = n - n1;
  if (n1 & 1 == 1) {
    cout << "NO";
  } else if (n2 & 1 == 0) {
    cout << "YES";
  } else if (n1 > 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
