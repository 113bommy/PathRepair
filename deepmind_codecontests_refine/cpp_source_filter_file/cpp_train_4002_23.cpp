#include <bits/stdc++.h>
using namespace std;
int main() {
  int b = 0;
  string a;
  cin >> a;
  if (a.size() >= 5) b++;
  for (int i = 0; i < a.size(); i++) {
    if (int(a[i]) >= 97 and int(a[i]) <= 122) {
      b++;
      break;
    }
  }
  for (int i = 0; i < a.size(); i++) {
    if (int(a[i]) >= 48 and int(a[i]) <= 57) {
      b++;
      break;
    }
  }
  for (int i = 0; i < a.size(); i++) {
    if (int(a[i]) <= 97 and int(a[i]) >= 65) {
      b++;
      break;
    }
  }
  if (b == 4)
    cout << "Correct" << endl;
  else
    cout << "Too weak" << endl;
  return 0;
}
