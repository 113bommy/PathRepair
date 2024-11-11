#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.);
template <class T>
inline T sq(T x) {
  return x * x;
}
bool endsWith(string a, string b) {
  if (a.length() < b.length()) return false;
  return a.substr(a.length() - b.length()) == b;
}
void solve() {
  string endings[6] = {"lios", "liala", "etr", "etra", "initis", "inites"};
  string word;
  int phase = -1, noun = 0, fst = 1, gender;
  while (cin >> word, cin) {
    int pat = -1;
    for (int i = (0); i < (6); ++i) {
      if (endsWith(word, endings[i])) {
        pat = i;
        break;
      }
    }
    if (pat < 0) {
      cout << "NO" << endl;
      return;
    }
    if (phase < 0) {
      phase = pat / 2;
      gender = pat & 1;
      if (phase == 1) noun = 1;
    } else if ((phase > pat / 2) || (phase == 1 && pat / 2 == 1) ||
               (gender != (pat & 1))) {
      cout << "NO" << endl;
      return;
    } else {
      phase = pat / 2;
      fst = 0;
      if (phase == 1) noun = 1;
    }
  }
  cout << (noun || fst ? "YES" : "NO") << endl;
  return;
}
int main() {
  solve();
  return 0;
}
