#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  string b;
  cin >> a;
  cin >> b;
  int x = a.size() - 1;
  int s = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[x]) {
      s++;
    }
    x--;
  }
  if (s == a.size()) {
    cout << "Yes";
  } else
    cout << "NO";
  return 0;
}
