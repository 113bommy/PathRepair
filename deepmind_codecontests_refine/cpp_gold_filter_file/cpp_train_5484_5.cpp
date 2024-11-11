#include <bits/stdc++.h>
using namespace std;
bool IsSubString(string& s_main, string& s_sub) {
  if (s_sub == "") return true;
  int preI = -1;
  for (int i = 0, j = 0; i < s_main.length(); i++) {
    if (s_main[i] == s_sub[j]) {
      if (preI == -1) preI = i;
      j++;
      if (j == s_sub.length()) return true;
    } else if (preI != -1) {
      i = preI;
      j = 0;
      preI = -1;
    }
  }
  return false;
}
int main() {
  string* strs = new string[100];
  int* qs = new int[100];
  for (int i = 0; i < 100; i++) {
    qs[i] = 0;
  }
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    int j = s.length() - 1;
    if (qs[j] == 0) {
      strs[j] = s;
      qs[j]++;
    } else if (strs[j] == s) {
      qs[j]++;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  s = "0";
  for (int i = 0; i < 100; i++) {
    if (s != "0" && qs[i] != 0) {
      if (!IsSubString(strs[i], s)) {
        cout << "NO" << endl;
        return 0;
      }
      s = strs[i];
    }
    if (s == "0") {
      if (qs[i] != 0) s = strs[i];
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < qs[i]; j++) {
      cout << strs[i] << endl;
    }
  }
}
