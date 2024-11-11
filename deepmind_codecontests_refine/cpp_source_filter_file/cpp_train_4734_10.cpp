#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  getline(cin, a);
  transform(a.begin(), a.end(), a.begin(), ::toupper);
  int p = a.size();
  for (int i = 2; i < a.size(); i++) {
    if (a[p - i] == 'A' || a[p - i] == 'E' || a[p - i] == 'I' ||
        a[p - i] == 'O' || a[p - i] == 'U' || a[p - i] == 'Y') {
      cout << "YES";
      break;
    } else if (a[p - i] == ' ') {
      continue;
    } else {
      cout << "NO";
      break;
    }
  }
}
