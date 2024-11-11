#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long cmp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}
int main() {
  char s[400000];
  gets(s);
  int v[400000];
  int count = 0;
  int point = 0;
  bool f = 1;
  int k = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '.' && i != strlen(s) - 1) {
      point++;
      if (!count && (k < 1 || k > 8)) {
        f = 0;
        break;
      }
      if (count == 0) {
        v[count] = (k + 1);
      } else if (count && (k > 1 && k < 12)) {
        if (k > 9) {
          v[count - 1] += (k - 8);
          v[count] = (8 + 1);
        } else {
          v[count - 1] += 1;
          v[count] = (k - 1 + 1);
        }
      } else {
        f = 0;
      }
      k = 0;
      count++;
    } else if (i == strlen(s) - 1) {
      if (k < 3 && k >= 0 && s[i] != '.' && point) {
        v[count - 1] += k + 1;
      } else {
        f = 0;
      }
    } else
      k++;
  }
  if (!f) {
    cout << "NO" << endl;
    return 0;
  } else {
    cout << "YES" << endl;
    int l = 0;
    for (int i = 0; i < count; i++) {
      int n = l;
      for (l = n; l < (n + v[i]); l++) cout << s[l];
      cout << endl;
    }
  }
}
