#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    string a;
    cin >> a;
    string b = "";
    if (a.length() <= 2) {
      cout << a;
      continue;
    }
    for (int i = 0; i < a.length(); i = i + 2) b += a[i];
    b = b + a[a.length() - 1];
    cout << b << endl;
  }
}
