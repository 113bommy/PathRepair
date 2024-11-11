#include <bits/stdc++.h>
using namespace std;
string invert(string s, int n) {
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      s[i] = '1';
    } else {
      s[i] = '0';
    }
  }
  return s;
}
string reverse(string s, int n) {
  string substr;
  for (int i = 0; i < n; i++) {
    substr += s[i];
  }
  for (int i = 0; i < substr.length() / 2; i++) {
    swap(substr[i], substr[substr.length() - i - 1]);
  }
  for (int i = n; i < s.length(); i++) {
    substr += s[i];
  }
  return substr;
}
void myFunc(int n, string a, string b) {
  vector<int> v;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == b[i]) {
      continue;
    }
    if (a[i] != b[i]) {
      if (a[0] == a[i]) {
        v.push_back(i + 1);
        a = invert(a, i + 1);
        a = reverse(a, i + 1);
      } else {
        v.push_back(1);
        if (a[0] == '0') {
          a[0] = '1';
        } else {
          a[0] = '0';
        }
        v.push_back(i + 1);
        a = invert(a, i + 1);
        a = reverse(a, i + 1);
      }
    }
  }
  cout << v.size() << " ";
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string a;
    string b;
    cin >> n >> a >> b;
    myFunc(n, a, b);
  }
}
