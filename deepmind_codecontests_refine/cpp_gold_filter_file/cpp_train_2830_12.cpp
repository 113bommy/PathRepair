#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s;
  cin >> t;
  queue<int> ab, ba;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' && t[i] == 'b') {
      ab.push(i + 1);
    }
    if (s[i] == 'b' && t[i] == 'a') {
      ba.push(i + 1);
    }
  }
  if ((ab.size() + ba.size()) % 2 == 1) {
    cout << "-1";
  } else {
    cout << ab.size() / 2 + ba.size() / 2 + (ab.size() % 2) * 2 << "\n";
    while (ab.size() > 1) {
      int x = ab.front();
      ab.pop();
      cout << x << " " << ab.front() << "\n";
      ab.pop();
    }
    while (ba.size() > 1) {
      int x = ba.front();
      ba.pop();
      cout << x << " " << ba.front() << "\n";
      ba.pop();
    }
    if (ba.size() == 1) {
      cout << ba.front() << " " << ba.front() << "\n";
      cout << ba.front() << " " << ab.front();
    }
  }
}
