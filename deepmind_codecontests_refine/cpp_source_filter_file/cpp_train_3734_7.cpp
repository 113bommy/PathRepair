#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  for (char c = 'a'; c <= 'z'; c++) {
    if (count(S.begin(), S.end(), c) % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
