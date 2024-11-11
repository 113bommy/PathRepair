#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 113;
const int INF = 1e9;
string s, t;
string getSimple(string pattern) {
  string ans = "";
  for (int i = 0; i < pattern.size(); ++i) {
    ans += (pattern[i] == 'A' ? '0' : '1');
  }
  return ans;
}
int sumS[N], sumT[N];
int suffS[N], suffT[N];
int main() {
  string p, q;
  cin >> p >> q;
  s = "0" + getSimple(p);
  t = "0" + getSimple(q);
  for (int i = 1; i < s.size(); ++i) {
    sumS[i] = sumS[i - 1] + s[i] - '0';
    suffS[i] = (s[i] == '1' ? 0 : suffS[i - 1] + 1);
  }
  for (int i = 1; i < t.size(); ++i) {
    sumT[i] = sumT[i - 1] + t[i] - '0';
    suffT[i] = (t[i] == '1' ? 0 : suffT[i - 1] + 1);
  }
  int t;
  cin >> t;
  for (int test = 0; test < t; ++test) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int oneS = sumS[b] - sumS[a - 1];
    int oneT = sumT[d] - sumT[c - 1];
    int zeroS = min(b - a + 1, suffS[b]);
    int zeroT = min(d - c + 1, suffT[d]);
    if (oneT < oneS) {
      cout << 0;
      continue;
    }
    if ((oneT - oneS) % 2) {
      cout << 0;
      continue;
    }
    if (zeroT > zeroS) {
      cout << 0;
      continue;
    }
    if (oneT == oneS) {
      if ((zeroS - zeroT) % 3) {
        cout << 0;
      } else {
        cout << 1;
      }
      continue;
    }
    if (zeroT == zeroS) {
      if (oneS == 0) {
        cout << 0;
        continue;
      }
      cout << 1;
      continue;
    }
    cout << 1;
  }
}
