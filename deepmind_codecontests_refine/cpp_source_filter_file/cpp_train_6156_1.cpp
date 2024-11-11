#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v) {
  for (int i = 0; i < (int)(v).size(); i++) cout << v[i] << " ";
  cout << endl;
}
void print(vector<vector<int> > v) {
  for (int i = 0; i < (int)(v).size(); i++) {
    for (int j = 0; j < (int)(v[i]).size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
void inc(long long first) {
  first++;
  first %= 998244353;
}
int main() {
  long long n;
  string s;
  cin >> n >> s;
  long long first = 1, second = 1;
  char c = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] == c)
      inc(first);
    else
      break;
  }
  char d = s[n - 1];
  for (int i = n - 1 - 1; i >= 0; i--) {
    if (s[i] == d)
      inc(second);
    else
      break;
  }
  if (c != d) {
    cout << (first + second + 1) % 998244353 << endl;
  } else {
    if (first == n) {
      cout << n * (n + 1) / 2 % 998244353 << endl;
    } else {
      cout << (first + 1) * (second + 1) % 998244353 << endl;
    }
  }
}
