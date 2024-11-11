#include <bits/stdc++.h>
using namespace std;
int dsu[26];
int size[26];
void assign() {
  for (int i = 0; i < 26; i++) {
    dsu[i] = i;
    size[i] = 1;
  }
}
int find(int i) {
  while (i != dsu[i]) {
    dsu[i] = dsu[dsu[i]];
    i = dsu[i];
  }
  return i;
}
void unionn(int x, int y) {
  int xx = find(x);
  int yy = find(y);
  if (size[xx] <= size[yy]) {
    size[yy] += size[xx];
    dsu[xx] = yy;
  } else {
    size[xx] += size[yy];
    dsu[yy] = xx;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s;
  bool exi[26] = {false};
  assign();
  for (int j = 0; j < int(n); j++) {
    cin >> s;
    exi[s[0] - 'a'] = true;
    for (int i = 1; i < s.size(); i++) {
      exi[s[i] - 'a'] = true;
      unionn(s[i] - 'a', s[0] - 'a');
    }
  }
  set<int> st;
  for (int i = 0; i < int(26); i++) {
    if (exi[i] == true) st.insert(find(i));
  }
  cout << st.size() << "\n";
  return 0;
}
