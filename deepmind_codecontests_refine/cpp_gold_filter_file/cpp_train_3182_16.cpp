#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool canbedone = true;
  int spam = 0;
  string str;
  getline(cin, str);
  while (spam < n) {
    getline(cin, str);
    int c = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
          str[i] == 'u' || str[i] == 'y') {
        c++;
      }
    }
    if (c != a[spam]) {
      canbedone = false;
      break;
    }
    spam++;
  }
  if (canbedone) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
