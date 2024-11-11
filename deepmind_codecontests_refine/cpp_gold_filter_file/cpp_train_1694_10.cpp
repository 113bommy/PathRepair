#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j, m;
  int a[1001], b[1001];
  string s1, s2, s3;
  cin >> t;
  while (t--) {
    cin >> n >> s2 >> s1;
    queue<int> q;
    s3 = s2;
    for (i = n - 1; i >= 0; i--) {
      if (s1[i] != s2[i]) {
        if (s2[i] != s2[0]) {
          q.push(1);
          s3[0] = s2[i];
        }
        q.push(i + 1);
        for (j = 0; j <= i; j++) {
          if (s3[i - j] == '0')
            s2[j] = '1';
          else
            s2[j] = '0';
        }
        s3 = s2;
      }
    }
    cout << q.size() << " ";
    n = q.size();
    while (!q.empty()) {
      j = q.front();
      q.pop();
      cout << j << " ";
    }
    cout << endl;
  }
}
