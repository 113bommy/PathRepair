#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  for (int i = 0; i < a.size() - 2; i++) {
    if ("AC" == a.substr(i, 2)) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
