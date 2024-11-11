#include <bits/stdc++.h>
using namespace std;
const char vow[5] = {'a', 'e', 'i', 'o', 'u'};
string S[4];
int C[4];
void doMagic() {
  if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3] && S[3] == S[0]) {
    C[0]++;
    C[1]++;
    C[2]++;
    C[3]++;
    return;
  }
  if (S[0] == S[1] && S[2] == S[3]) {
    C[1]++;
    return;
  }
  if (S[0] == S[2] && S[1] == S[3]) {
    C[2]++;
    return;
  }
  if (S[0] == S[3] && S[1] == S[2]) {
    C[3]++;
    return;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      string tmp;
      cin >> tmp;
      int cnt = 0;
      for (int i = tmp.length() - 1; i >= 0 && cnt < k; i--) {
        for (int j = 0; j < 4; j++)
          if (tmp[i] == vow[j]) {
            cnt++;
            break;
          }
        S[j].push_back(tmp[i]);
      }
      if (cnt < k) {
        cout << "NO";
        goto exit;
      }
    }
    doMagic();
  }
  if (C[0] == n) {
    cout << "aaaa";
    goto exit;
  }
  if (C[1] == n) {
    cout << "aabb";
    goto exit;
  }
  if (C[2] == n) {
    cout << "abab";
    goto exit;
  }
  if (C[3] == n) {
    cout << "abba";
    goto exit;
  }
  cout << "NO";
exit:
  return (0);
}
