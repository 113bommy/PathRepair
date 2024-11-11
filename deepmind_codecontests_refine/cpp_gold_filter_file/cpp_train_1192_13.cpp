#include <bits/stdc++.h>
using namespace std;
int found(vector<char> v, char c) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == c) {
      return i;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<char> first = {'-', 'q', 'w', 'e', 'r', 't', 'y',
                        'u', 'i', 'o', 'p', '[', ']', '\\'};
  vector<char> second = {'-', 'a', 's', 'd', 'f', 'g',
                         'h', 'j', 'k', 'l', ';', '\''};
  vector<char> third = {'-', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
  char ch;
  cin >> ch;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    int a = found(first, s[i]);
    int b = found(second, s[i]);
    int c = found(third, s[i]);
    if (a) {
      if (ch == 'L') {
        cout << first[a + 1];
      } else {
        cout << first[a - 1];
      }
    } else if (b) {
      if (ch == 'L') {
        cout << second[b + 1];
      } else {
        cout << second[b - 1];
      }
    } else {
      if (ch == 'L') {
        cout << third[c + 1];
      } else {
        cout << third[c - 1];
      }
    }
  }
}
