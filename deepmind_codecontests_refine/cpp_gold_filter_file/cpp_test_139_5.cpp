#include <bits/stdc++.h>
using namespace std;
int main() {
  int n{0};
  string A;
  cin >> n;
  while (cin >> A) {
    string sub1 = A.substr(0, (A.length() / 2));
    string sub2 = A.substr((A.length() / 2), A.length());
    if (sub1 != sub2) {
      cout << "NO" << '\n';
    } else if (sub1 == sub2) {
      cout << "YES" << '\n';
    }
  }
}
