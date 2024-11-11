#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  if (a.size() != b.size()) {
    cout << "No";
    return 0;
  }
  for (int i = 0; i < a.size(); i++) {
    if ((a[i] == 97 || a[i] == 101 || a[i] == 105 || a[i] == 111 ||
         a[i] == 117) &&
        (b[i] == 97 || b[i] == 101 || b[i] == 105 || b[i] == 111 ||
         b[i] == 117))
      continue;
    else if ((a[i] != 97 && a[i] != 101 && a[i] != 105 &&
              a[i] != 111 & a[i] != 117) &&
             (b[i] != 97 && b[i] != 101 && b[i] != 105 && b[i] != 111 &&
              b[i] != 117))
      continue;
    else {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
