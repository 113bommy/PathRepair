#include <bits/stdc++.h>
using namespace std;
int main() {
  long long siz, pos = 0, k;
  string s;
  cin >> siz;
  k = siz;
  set<char> dig;
  vector<vector<char>> v;
  while (siz--) {
    cin >> s;
    vector<char> tmpv;
    for (long long i = 0; i < k; i++) {
      tmpv.push_back(s[i]);
    }
    v.push_back(tmpv);
  }
  for (long long i = 0; i < k; i++) {
    for (long long j = 0; j < k; j++) {
      if (i == j || (j - k - 1) == i) {
        dig.insert(v[i][j]);
      }
    }
  }
  if (dig.size() == 1) {
    long long flag = 0;
    set<char> other;
    char ck = v[0][0];
    for (long long i = 0; i < k; i++) {
      for (long long j = 0; j < k; j++) {
        if (i != j && (k - 1 - i) != j) {
          if (v[i][j] != ck) {
            other.insert(v[i][j]);
          } else {
            flag = 1;
            break;
          }
        }
      }
    }
    if (other.empty() || flag == 1) {
      cout << "NO";
    } else if (other.size() > 1) {
      cout << "NO";
    } else {
      cout << "YES";
    }
  } else {
    cout << "NO";
  }
  return 0;
}
