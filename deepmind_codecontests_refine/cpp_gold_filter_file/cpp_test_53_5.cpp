#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    char a;
    cin >> a;
    string s;
    cin >> s;
    long long ss = s.size();
    bool flag = true;
    long long k, c = 0;
    int x;
    bool ff = true;
    for (int i = 0; i < ss; i++) {
      if (s[i] != a) {
        ff = false;
      }
    }
    if (ff) {
      cout << 0 << endl;
      continue;
    }
    if (ss % 2 == 0) {
      x = (ss / 2) + 1;
    } else {
      x = (ss / 2) + 1;
    }
    bool fl = false;
    for (long long i = x; i <= ss; i++) {
      if (s[i - 1] == a) {
        fl = true;
        c = i;
        break;
      }
    }
    if (fl) {
      cout << 1 << endl;
      cout << c << endl;
    } else {
      cout << 2 << endl;
      cout << ss << " " << ss - 1 << endl;
    }
  }
}
