#include <bits/stdc++.h>
const int inf = 1000006;
using namespace std;
int b[inf], str[inf], e[inf];
bool v1[26], v2[26];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    str[i] = x - 'A';
  }
  for (int i = n - 1; i >= 0; i--) {
    int a = str[i];
    if (!v1[a]) {
      e[i]++;
      v1[a] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    int a = str[i];
    if (!v2[a]) {
      v2[a] = true;
      b[i]++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += b[i];
    if (cnt > k) {
      cout << "YES";
      return 0;
    }
    cnt -= e[i];
  }
  cout << "NO";
  return 0;
}
