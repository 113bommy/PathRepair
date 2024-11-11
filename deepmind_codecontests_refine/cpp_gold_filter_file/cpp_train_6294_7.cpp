#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> vec(3, 0);
  string s;
  for (int i = 0; i < 3; i++) {
    cin >> s;
    if (s[1] == '>') {
      vec[s[0] - 'A']++;
    } else {
      vec[s[2] - 'A']++;
    }
  }
  if (vec[0] == 1 && vec[1] == 1) {
    cout << "Impossible";
  } else {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (vec[j] == i) {
          s[i] = char('A' + j);
        }
      }
    }
    cout << s;
  }
}
