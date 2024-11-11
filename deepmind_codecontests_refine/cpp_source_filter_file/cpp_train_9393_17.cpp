#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1)
      cout << "-1" << endl;
    else {
      for (int i = 0; i < n - 1; i++) cout << "7";
      cout << "6" << endl;
    }
  }
}
