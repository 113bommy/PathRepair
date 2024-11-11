#include <bits/stdc++.h>
using namespace std;
void print2(vector<vector<int>> X) {
  for (int i = 0; i < X.size(); i++) {
    for (int j = 0; j < X[i].size(); j++) {
      cout << X[i][j] << " ";
    }
    cout << endl;
  }
  return;
}
void print(vector<char> B) {
  for (int i = 0; i < B.size(); i++) {
    cout << B[i];
  }
  cout << endl;
}
bool solve2(string s, vector<char> A, vector<char> B) {
  int a = A.size();
  int b = B.size();
  vector<int> C(b + 1, 0);
  vector<vector<int>> X(a + 1, C);
  int k = 0;
  for (int i = 1; i < a + 1; i++) {
    while (k < s.length() && s[k] != A[i - 1]) {
      k++;
    }
    if (k == s.length()) {
      return false;
    }
    X[i][0] = k;
    k++;
  }
  k = 0;
  for (int i = 1; i < b + 1; i++) {
    while (k < s.length() && s[k] != B[i - 1]) {
      k++;
    }
    if (k == s.length()) {
      return false;
    }
    X[0][i] = k;
    k++;
  }
  for (int i = 1; i < a + 1; i++) {
    for (int j = 1; j < b + 1; j++) {
      int k = X[i - 1][j] + 1;
      while (k < s.length() && s[k] != A[i - 1]) {
        k++;
      }
      int l = X[i][j - 1] + 1;
      while (l < s.length() && s[l] != B[j - 1]) {
        l++;
      }
      if (k == s.length() && l == s.length()) {
        return false;
      }
      X[i][j] = min(k, l);
    }
  }
  return true;
}
bool solve(string s, string t) {
  int i = 0;
  int k = 0;
  while (i < t.length()) {
    while (k < s.length() && s[k] != t[i]) {
      k++;
    }
    i++;
    k++;
  }
  if (k < s.length()) {
    return true;
  }
  for (int i = 1; i < t.length(); i++) {
    vector<char> A;
    vector<char> B;
    for (int j = 0; j < i; j++) {
      A.push_back(t[j]);
    }
    for (int j = i; j < t.length(); j++) {
      B.push_back(t[j]);
    }
    if (solve2(s, A, B) == true) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t1 = 0; t1 < T; t1++) {
    string t, s;
    cin >> s >> t;
    if (solve(s, t) == true) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
