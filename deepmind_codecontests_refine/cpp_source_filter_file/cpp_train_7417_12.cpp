#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    string b;
    int n = a.length();
    b.push_back(a[0]);
    for (int i = 1; i < n - 1; i++) {
      b.push_back(a[i]);
      i++;
    }
    b.push_back(a[n - 1]);
    cout << b;
  }
}
