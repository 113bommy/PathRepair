#include <bits/stdc++.h>
using namespace std;
vector<string> word;
vector<int> be, af;
set<int> g;
int sf(string s) {
  int n = s.size();
  if (n >= 4 && s.substr(n - 4, 4) == "lios") {
    return 0;
  } else if (n >= 5 && s.substr(n - 5, 5) == "liala") {
    return 1;
  } else if (n >= 3 && s.substr(n - 3, 3) == "etr") {
    return 2;
  } else if (n >= 4 && s.substr(n - 4, 4) == "etra") {
    return 3;
  } else if (n >= 6 && s.substr(n - 6, 6) == "initis") {
    return 4;
  } else if (n >= 6 && s.substr(n - 6, 6) == "inites") {
    return 5;
  } else {
    return -1;
  }
}
int main() {
  string s;
  while (cin >> s) {
    word.push_back(s);
  }
  for (int i = 0; i < word.size(); i++) {
    int j = sf(word[i]);
    if (j == -1) {
      cout << "NO" << endl;
      return 0;
    }
    g.insert(j % 2);
    be.push_back(j / 2);
    af.push_back(j / 2);
  }
  if (word.size() == 1) {
    cout << "YES" << endl;
    return 0;
  }
  sort(af.begin(), af.end());
  if (g.size() != 1) {
    cout << "NO" << endl;
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < af.size(); i++) {
    if (af[i] != be[i]) {
      cout << "NO" << endl;
      return 0;
    }
    if (af[i] == 1) {
      cnt++;
    }
  }
  if (cnt == 0 && word.size() != 1) {
    cout << "NO" << endl;
    return 0;
  } else if (cnt != 1 && cnt != 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
