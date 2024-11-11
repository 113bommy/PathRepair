#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return b != 0 ? GCD(b, a % b) : a; }
long long LCM(long long a, long long b) { return a * (b / GCD(a, b)); }
long long Pow(long long n, long long e) {
  if (e == 0) return 1;
  if (e == 1)
    return n;
  else if (e & 1) {
    long long t = Pow(n, e / 2);
    return n * t * t;
  } else {
    long long t = Pow(n, e / 2);
    return t * t;
  }
}
vector<int> idsHere[100005];
int id = 1;
vector<int> back;
void KMPInit(string& s) {
  back.resize((int)(s).size() + 1);
  int i = 0, j = -1;
  back[0] = -1;
  while (i < (int)(s).size()) {
    while (j >= 0 && s[i] != s[j]) j = back[j];
    ++i;
    ++j;
    back[i] = j;
  }
}
void KMP(string& needle, string& hey) {
  int i = 0, j = 0;
  while (i < (int)(hey).size()) {
    while (j >= 0 && hey[i] != needle[j]) j = back[j];
    ++i;
    ++j;
    if (j == (int)(needle).size()) {
      idsHere[i - 1].push_back(id);
      idsHere[i - 1 - (int)(needle).size() + 1].push_back(id);
      ++id;
      j = 0;
    }
  }
}
int main() {
  string s;
  getline(cin, s);
  vector<string> v;
  int N;
  scanf("%d", &N);
  for (int i = 0, max_ = (N); i < max_; ++i) {
    string ss;
    cin >> ss;
    v.push_back(ss);
  }
  for (int i = 0, max_ = (N); i < max_; ++i) {
    KMPInit(v[i]);
    KMP(v[i], s);
  }
  map<int, int> m;
  int len = 0, pos = 0, i = 0, j = 0;
  while (j < (int)(s).size()) {
    bool ok = true;
    for (int k = 0, max_ = ((int)(idsHere[j]).size()); k < max_; ++k)
      if (++m[idsHere[j][k]] > 1) ok = false;
    while (!ok) {
      for (int k = 0, max_ = ((int)(idsHere[i]).size()); k < max_; ++k)
        --m[idsHere[i][k]];
      ++i;
      ok = true;
      for (int k = 0, max_ = ((int)(idsHere[j]).size()); k < max_; ++k)
        if (m[idsHere[j][k]] > 1) {
          ok = false;
          break;
        }
    }
    ++j;
    if (len < j - i) {
      len = j - i;
      pos = i;
    }
  }
  printf("%d %d\n", len, pos);
  return 0;
}
