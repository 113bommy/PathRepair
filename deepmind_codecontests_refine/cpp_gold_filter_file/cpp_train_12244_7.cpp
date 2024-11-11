#include <bits/stdc++.h>
using namespace std;
int a[26];
int main(void) {
  int aa, b;
  cin >> aa >> b;
  string tmp;
  cin >> tmp;
  for (int e = 0; e < tmp.size(); e++) {
    a[tmp[e] - 'a']++;
  }
  for (int e = 0; e < 26; e++) {
    if ((a[e] > b)) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
