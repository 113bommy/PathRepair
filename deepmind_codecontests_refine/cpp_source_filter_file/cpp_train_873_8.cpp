#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string a[100];
  bool good = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int counter = 0;
  for (int i = 0; i < n; i++) {
    good = true;
    for (int j = 0; j <= k; j++) {
      if (a[i].find(to_string(i)) == string::npos) {
        good = false;
      }
    }
    if (good == true) counter++;
  }
  cout << counter;
}
