#include <bits/stdc++.h>
using namespace std;
string a;
int main() {
  cin >> a;
  if (a == string(a.size(), 'a')) {
    cout << string(a.size() - 1, 'a') << "z" << endl;
  } else {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != 'a') {
        int x = i;
        while (x < a.size() && a[x] != 'a') {
          a[x++]--;
        }
        break;
      }
    }
  }
  cout << a << endl;
  return 0;
}
