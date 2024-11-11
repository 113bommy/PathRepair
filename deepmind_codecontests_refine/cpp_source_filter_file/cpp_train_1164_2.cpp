#include <bits/stdc++.h>
const int MOD = (int)1e9 + 7;
const double eps0 = 1e-6;
const double eps = 1e-9;
const long double eps2 = 1e-18;
using namespace std;
int N, K;
string s;
vector<int> pos;
int rep;
void sfind() {
  int len = (int)(s).size();
  size_t idx = 0;
  pos.clear();
  do {
    idx = s.find("47", idx);
    if (idx != string::npos) {
      pos.push_back(idx);
      idx += 2;
    } else {
      break;
    }
  } while (idx != string::npos);
}
int main(void) {
  while (cin >> N >> K) {
    cin >> s;
    sfind();
    rep = -1;
    int cnt = 0;
    for (int i = 0; i < (int)(pos).size() && rep == -1; i++) {
      if (pos[i] % 2 || pos[i] != (int)(s).size() - 2) {
        if (pos[i] % 2 == 0 && s[pos[i] + 2] == '7') {
          rep = i;
        } else if (pos[i] % 2 == 1 && s[pos[i] - 1] == '4') {
          rep = i;
        }
      }
      cnt++;
    }
    if (rep == -1) {
      int i = 0;
      while (K > 0 && i < cnt) {
        if (pos[i] % 2) {
          s[pos[i]] = '7';
        } else {
          s[pos[i] + 1] = '4';
        }
        i++;
        K--;
      }
      if (0) cout << "cnt: " << cnt << endl;
      if (0) {
        cout << (int)(pos).size() << endl;
        for (int i = 0; i < ((int)(pos).size()); i++) {
          cout << "pos:" << pos[i] << endl;
        }
      }
      cout << s << endl;
    } else {
      int i = 0;
      cnt--;
      while (K > 0 && i < cnt) {
        if (pos[i] % 2) {
          s[pos[i]] = '7';
        } else {
          s[pos[i] + 1] = '4';
        }
        i++;
        K--;
      }
      if (0) cout << "now,K=" << K << " s: " << s << endl;
      if (K > 0) {
        if (K % 2 == 0)
          cout << s << endl;
        else {
          if (rep % 2) {
            s[pos[rep]] = '7';
          } else {
            s[pos[rep] + 1] = '4';
          }
          cout << s << endl;
        }
      } else {
        cout << s << endl;
      }
    }
  }
}
