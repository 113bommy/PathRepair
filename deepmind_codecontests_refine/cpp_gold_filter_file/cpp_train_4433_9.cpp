#include <bits/stdc++.h>
using namespace std;
int n, cnt[4];
string s;
int M() {
  int i = 0;
  for (int j = 0; j < 4; j++) {
    if (cnt[i] > cnt[j]) {
      i = j;
    }
  }
  return i;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      cnt[0]++;
    }
    if (s[i] == 'C') {
      cnt[1]++;
    }
    if (s[i] == 'G') {
      cnt[2]++;
    }
    if (s[i] == 'T') {
      cnt[3]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != '?') {
      continue;
    }
    int k = M();
    if (k == 0) {
      s[i] = 'A';
    }
    if (k == 1) {
      s[i] = 'C';
    }
    if (k == 2) {
      s[i] = 'G';
    }
    if (k == 3) {
      s[i] = 'T';
    }
    cnt[k]++;
  }
  for (int i = 0; i < 4; i++) {
    if (cnt[i] != cnt[0]) {
      cout << "===" << endl;
      return 0;
    }
  }
  cout << s << endl;
  return 0;
}
