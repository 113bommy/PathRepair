#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
  return;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v(n);
  v[0] = 1;
  char c = s[0];
  for (int i = 1; i < s.length(); i++) {
    if (s[i] >= c) {
      v[i] = 1;
      c = s[i];
    }
  }
  bool found = false;
  c = 'a';
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
      if (s[i] >= c) {
        c = s[i];
      } else {
        found = true;
        break;
      }
    }
  }
  if (found == false) {
    cout << "YES"
         << "\n";
    print(v);
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}
