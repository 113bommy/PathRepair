#include <bits/stdc++.h>
using namespace std;
int main() {
  string m[3] = {"lios", "etr", "initis"};
  string w[3] = {"liala", "etra", "inites"};
  string s;
  getline(cin, s);
  int i = 0;
  int last = -1;
  bool gender = 0;
  bool ok = true;
  int noun = 0, words = 0;
  while (i < s.size()) {
    int j = i;
    string t;
    while (j < s.size() and s[j] != ' ') {
      t.push_back(s[j]);
      j++;
    }
    if (t.size() < 3) {
      ok = false;
      break;
    }
    bool curr_gen = 0;
    int curr = -1;
    words++;
    for (int k = 0; k < 3; k++) {
      if ((int)(t.size() - m[k].size()) >= 0 and
          t.substr((int)(t.size() - m[k].size()), m[k].size()) == m[k]) {
        curr_gen = 0;
        curr = k;
        break;
      }
      if ((int)(t.size() - w[k].size()) >= 0 and
          t.substr((int)(t.size() - w[k].size()), w[k].size()) == w[k]) {
        curr_gen = 1;
        curr = k;
        break;
      }
    }
    if ((curr == -1) or (last != -1 and curr_gen != gender) or
        (last != -1 and curr < last)) {
      ok = false;
      break;
    }
    if (curr == 1) {
      noun += 1;
    }
    last = curr;
    gender = curr_gen;
    i = j + 1;
  }
  if ((ok and (words == 1)) or (ok and (noun == 1))) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
