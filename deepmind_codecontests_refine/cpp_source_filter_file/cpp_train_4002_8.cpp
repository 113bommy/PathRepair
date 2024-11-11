#include <bits/stdc++.h>
using namespace std;
int main() {
  int s = 0, c = 0, d = 0, r = 0;
  string str, str1;
  int l, l1;
  getline(cin, str);
  l = str.length();
  char arr[l];
  str.copy(arr, l);
  for (int i = 0; i < l; i++) {
    if (int(arr[i]) >= 97 && int(arr[i]) <= 122) {
      s++;
    } else if (int(arr[i]) >= 65 && int(arr[i]) <= 90) {
      c++;
    } else if (int(arr[i]) >= 48 && int(arr[i]) <= 57) {
      d++;
    } else {
      r++;
    }
  }
  if (s > 0 && c > 0 && d > 0 && r > 0 && l >= 5) {
    cout << "Correct";
  } else {
    cout << "Too weak";
  }
}
