#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(26, 0), v1(26, 0);
    char a[200], b[200];
    scanf("%s %s", a, b);
    for (int i = 0; i < n; i++) {
      v[a[i] - 'a']++;
      v1[b[i] - 'a']++;
    }
    int flag = 1;
    for (int i = 0; i < 26; i++) {
      if (v[i] != v1[i]) {
        flag = 0;
        break;
      }
    }
    if (flag == 0) {
      cout << "-1" << endl;
    } else {
      long long int cnt = 1000000000, k;
      for (int i = 0; i < n; i++) {
        k = i;
        for (int j = 0; j < n; j++) {
          if (k < n && b[k] == a[j]) {
            k++;
          }
        }
        cnt = min(cnt, n - k + i);
      }
      cout << cnt << endl;
    }
  }
}
