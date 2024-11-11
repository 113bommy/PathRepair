#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int> > vt;
int main() {
  string st;
  cin >> st;
  stack<string> x;
  vector<string> v;
  string tp = "";
  for (int i = 0; i < st.size(); ++i) {
    if (st[i] == '<' || st[i] == '>') continue;
    if (st[i] == '/') {
      tp = "/";
      tp.append(1, st[i + 1]);
      i++;
      v.push_back(tp);
      continue;
    }
    tp = "";
    tp.append(1, st[i]);
    v.push_back(tp);
  }
  int sp = 0;
  for (int i = 0; i < v.size(); ++i) {
    string tp1 = v[i];
    if (x.empty() || tp1[0] != '/') {
      x.push(tp1);
      vt.push_back(make_pair(tp1, sp));
      for (int j = 0; j < sp; ++j) cout << " ";
      cout << "<" << tp1 << ">" << endl;
      sp++;
      continue;
    }
    string tp2 = x.top();
    if (tp2[0] == tp1[1]) {
      sp--;
      for (int j = 0; j < sp; ++j) cout << " ";
      cout << "<" << tp1 << ">" << endl;
      x.pop();
    }
  }
  return 0;
}
