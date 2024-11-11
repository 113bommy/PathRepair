#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++) {
      cin >> str[i];
    }
    vector<int> ch(25);
    for (int i = 0; i < n; i++) {
      for (char l : str[i]) {
        ch[((int)l) - 'a']++;
      }
    }
    bool aaa = false;
    for (int i = 0; i < 25; i++) {
      if (ch[i] % n != 0) {
        aaa = true;
        break;
      }
    }
    if (aaa)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
