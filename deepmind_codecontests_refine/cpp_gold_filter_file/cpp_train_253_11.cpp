#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1.0);
int main() {
  string s;
  cin >> s;
  int cont = 0;
  int v[s.size()], mini[s.size()];
  int curr = 0;
  bool f = 0;
  for (int i = (0); i < (s.size()); i++) {
    if (s[i] == '(')
      v[i] = ++curr;
    else if (s[i] == ')')
      v[i] = --curr;
    else {
      cont++;
      v[i] = curr;
    }
    if (curr < 0) f = 1;
  }
  if (f) {
    puts("-1");
  } else {
    vector<int> ans;
    mini[s.size() - 1] = v[s.size() - 1];
    for (int i = s.size() - 2; i >= 0; i--) {
      mini[i] = min(mini[i + 1], v[i]);
    }
    curr = 0;
    for (int i = (0); i < (s.size()); i++) {
      if (s[i] == '#') {
        if (cont == 1)
          ans.push_back(mini[i] - curr);
        else
          ans.push_back(1);
        if (mini[i] == curr) f = 1;
        curr += ans.back();
        cont--;
      }
    }
    int j = 0;
    curr = 0;
    for (int i = (0); i < (s.size()); i++) {
      if (s[i] == '(')
        ++curr;
      else if (s[i] == ')')
        --curr;
      else
        curr -= ans[j++];
      if (curr < 0) f = 1;
    }
    if (curr > 0) f = 1;
    if (f) {
      puts("-1");
    } else {
      for (int i = (0); i < (ans.size()); i++) cout << ans[i] << endl;
    }
  }
}
