#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int Map[27][27];
  char word1[50005], word2[50005];
  memset(Map, 0x3f, sizeof(Map));
  for (int i = 1; i <= 26; i++) Map[i][i] = 0;
  scanf("%s", word1 + 1);
  scanf("%s", word2 + 1);
  if (strlen(word1 + 1) != strlen(word2 + 1)) {
    cout << "-1" << endl;
    return 0;
  }
  unsigned long length = strlen(word1 + 1);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char ai, bi;
    int int_ai, int_bi;
    int wi;
    cin >> ai >> bi >> wi;
    int_ai = ai - 96;
    int_bi = bi - 96;
    Map[int_ai][int_bi] = min(Map[int_ai][int_bi], wi);
  }
  for (int k = 1; k <= 26; k++)
    for (int i = 1; i <= 26; i++)
      for (int j = 1; j <= 26; j++)
        Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
  char answer[50005];
  for (int i = 1; i <= length; i++) answer[i] = word1[i];
  int path = 0;
  for (int i = 1; i <= length; i++) {
    if (word1[i] == word2[i]) continue;
    int int_word1 = word1[i] - 96, int_word2 = word2[i] - 96;
    int ans = 50005;
    for (int j = 1; j <= 26; j++) {
      if (Map[int_word1][j] != 50005 && Map[int_word2][j] != 50005)
        if (Map[int_word1][j] + Map[int_word2][j] < ans) {
          ans = Map[int_word1][j] + Map[int_word2][j];
          answer[i] = j + 96;
        }
    }
    if (ans == 50005) {
      cout << "-1";
      return 0;
    }
    path += ans;
  }
  cout << path << endl;
  for (int i = 1; i <= length; i++) cout << answer[i];
}
