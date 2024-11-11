#include <bits/stdc++.h>
using namespace std;
int n, id = 0;
int Hash[333], L[333];
map<string, int> M;
vector<int> v;
int kmp(int Len) {
  int len = v.size();
  int lps[len], I = 0, num = 0;
  lps[0] = 0;
  for (int i = 1; i < len; i++) {
    if (v[I] != v[i]) I = -1;
    lps[i] = ++I;
  }
  int i = 0, j = 0;
  while (i < n) {
    if (Hash[i] == v[j]) {
      i++;
      j++;
    } else {
      if (j == 0)
        i++;
      else {
        if (j == lps[j])
          j = 0;
        else
          j = lps[j - 1];
      }
    }
    if (j == len) {
      num++;
      j = 0;
    }
  }
  if (num == 1) num = 0;
  return (Len - 1) * num;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  int Len = 0, res = 0, len;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (!M[s]) {
      M[s] = ++id;
    }
    Hash[i] = M[s];
    L[i] = s.length();
    Len += L[i];
  }
  Len += (n - 1);
  for (int i = 0; i < n; i++) {
    v.clear();
    len = 0;
    for (int j = i; j < n; j++) {
      v.push_back(Hash[j]);
      len += L[j];
      res = max(res, kmp(len));
    }
  }
  cout << Len - res << endl;
  return 0;
}
