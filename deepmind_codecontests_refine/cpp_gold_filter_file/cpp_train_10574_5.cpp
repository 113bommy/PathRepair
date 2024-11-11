#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T mdINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
template <class T>
bool ISLEFT(T a, T b, T c) {
  if (((a.first.first - b.first.first) * (b.second.second - c.second.second) -
       (b.first.first - c.first.first) * (a.second.second - b.second.second)) <
      0.0)
    return 1;
  else
    return 0;
}
int main() {
  string first;
  cin >> first;
  string s = "BGRY";
  map<char, int> mp;
  do {
    bool fl = 0;
    for (int i = 0; i < 4; i++) {
      if (first[i] == '!')
        continue;
      else if (first[i] != s[i])
        fl = 1;
    }
    if (!fl) {
      string h = s;
      mp.clear();
      for (int i = 0; i <= 3; i++)
        if (first[i] == '!') {
          mp[s[i]]++;
        }
      for (int i = 4; i < first.size(); i++) {
        if (first[i] == '!') {
          char t = h[i - 4];
          h += t;
          mp[t]++;
        } else if (first[i] != h[i - 4]) {
          fl = 1;
        } else {
          char t = h[i - 4];
          h += t;
        }
      }
      if (!fl) {
        break;
      }
    }
  } while (next_permutation(s.begin(), s.end()));
  printf("%d %d %d %d\n", mp['R'], mp['B'], mp['Y'], mp['G']);
  return 0;
}
