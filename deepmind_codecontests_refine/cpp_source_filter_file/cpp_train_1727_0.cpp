#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  cin >> n;
  for (int i = 0; i < n.size() / 2; i++) {
    if (n[i] == '1' || n[i] == '2') {
      cout << "No" << endl;
      return 0;
    }
    if (n[i] == '3' || n[i] == '7') {
      if (n[n.size() - 1 - i] != n[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
    if (n[i] == '4') {
      if (n[n.size() - 1 - i] != '6') {
        cout << "No" << endl;
        return 0;
      }
    }
    if (n[i] == '5') {
      if (n[n.size() - 1 - i] != '9') {
        cout << "No" << endl;
        return 0;
      }
    }
    if (n[i] == '6') {
      if (n[n.size() - 1 - i] != '4') {
        cout << "No" << endl;
        return 0;
      }
    }
    if (n[i] == '8') {
      if (n[n.size() - 1 - i] != '0') {
        cout << "No" << endl;
        return 0;
      }
    }
    if (n[i] == '9') {
      if (n[n.size() - 1 - i] != '5') {
        cout << "No" << endl;
        return 0;
      }
    }
    if (n[i] == '0') {
      if (n[n.size() - 1 - i] != '8') {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
