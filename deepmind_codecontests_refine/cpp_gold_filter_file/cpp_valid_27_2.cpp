#include <bits/stdc++.h>
using namespace std;
long long int t, n, m, k;
string str, striki;
int main() {
  cin >> t;
  while (t--) {
    cin >> str;
    cin >> striki;
    long long int pos = striki.size() - 1;
    long long int durum = false;
    for (long long int i = str.size() - 1; i >= 0; i--) {
      if (str[i] == striki[pos]) {
        pos--;
      } else {
        i--;
      }
      if (pos <= -1) {
        durum = true;
        break;
      }
    }
    if (durum)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
