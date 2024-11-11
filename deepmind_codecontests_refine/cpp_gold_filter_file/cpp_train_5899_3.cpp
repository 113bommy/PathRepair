#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  cin >> n;
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n.size(); i++) {
    if (n[i] == 'b' && n[i + 1] == 'a') {
      cout << "NO";
      return 0;
    }
    if (n[i] == 'c' && (n[i + 1] == 'a' || n[i + 1] == 'b')) {
      cout << "NO";
      return 0;
    }
  }
  for (int j = 0; j < n.size(); j++) {
    if (n[j] == 'a') {
      a++;
    } else if (n[j] == 'b') {
      b++;
    } else {
      c++;
    }
  }
  if (a < 1 || b < 1) {
    cout << "NO";
    return 0;
  }
  if (c != a && c != b) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
