#include <bits/stdc++.h>
using namespace std;
int N, K, M;
string S;
int c[2009][30];
bool b[2009][109];
void Init() {
  for (int i = 0; i < 26; i++) c[1][i] = 0;
  for (int i = 0; i < N; i++) c[1][S[i] - 'a']++;
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j < 26; j++) c[i][j] = c[1][j];
    for (int j = 0; j < N; j++) b[i][j] = true;
  }
  cin >> M;
  for (int i = 1; i <= M; i++) {
    int p_num;
    char p_ch;
    cin >> p_num >> p_ch;
    for (int j = 1; j <= K; j++) {
      if (c[j][p_ch - 'a'] < p_num)
        p_num -= c[j][p_ch - 'a'];
      else {
        for (int k = 0; k < N; k++)
          if (b[j][k] && S[k] == p_ch) {
            p_num--;
            if (p_num == 0) {
              b[j][k] = false;
              c[j][p_ch - 'a']--;
              break;
            }
          }
        break;
      }
    }
  }
  for (int i = 1; i <= K; i++)
    for (int j = 0; j < N; j++)
      if (b[i][j]) cout << S[j];
}
int main() {
  cin >> K;
  cin >> S;
  N = S.size();
  Init();
}
