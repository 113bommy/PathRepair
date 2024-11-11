#include <bits/stdc++.h>
using namespace std;
bool check(int a) {
  for (int i = 3;; ++i) {
    if (((i - 2) * 180) % i == 0 && ((i - 2) * 180) / i == a) return true;
    if (((i - 2) * 180) / i > a) return false;
  }
}
int main() {
  int n;
  cin >> n;
  int a[1000];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (check(i) == true) {
      cout << "YES";
    }
    if (check(i) == false) {
      cout << "NO";
    }
    cout << endl;
  }
}
