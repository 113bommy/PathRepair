#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  vector<string> k;
  for (int i = 0; i < a; i++) {
    string n;
    cin >> n;
    bool s = 0;
    for (int j = 0; j < k.size(); j++) {
      if (k[j] == n) {
        s = true;
      }
    }
    if (!s) {
      k.push_back(n);
      cout << "NO";
    } else {
      cout << "YES" << endl;
    }
  }
}
