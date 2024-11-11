#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  std::vector<string> names(n, "");
  std::vector<string> s(n);
  std::vector<string> posnames(50, "");
  bool ifyes = false;
  for (int i = 0; i < 26; i++) {
    posnames[i] = "A" + string(1, char('a' + i));
  }
  for (int i = 26; i < 50; i++) {
    posnames[i] = "B" + string(1, char('a' + i - 26));
  }
  for (int i = 0; i < n - k + 1; ++i) {
    cin >> s[i];
  }
  int pos = 0;
  for (int i = 0; i < n - k + 1; ++i) {
    if (s[i] == "YES") {
      if (!ifyes) {
        for (int j = 0; j <= i; ++j) {
          names[j] = posnames[i];
        }
      }
      ifyes = true;
      for (int j = i + 1; j < i + k; j++) {
        if (names[j] == "") names[j] = posnames[j];
        pos++;
      }
    } else if (!ifyes) {
    } else {
      names[i + k - 1] = names[i];
    }
  }
  if (!ifyes) {
    for (int i = 0; i < n; ++i) {
      cout << "Namesi"
           << " ";
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << names[i] << " ";
  }
}
