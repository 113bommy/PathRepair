#include <bits/stdc++.h>
using namespace std;
const int Plen = 100005;
int lenp, lent, N;
char text[100005];
char pat[Plen];
int F[Plen];
void build_F(char *pat) {
  lenp = strlen(pat);
  F[0] = F[1] = 0;
  int i, j;
  for (i = 2; i <= lenp; i++) {
    j = F[i - 1];
    while (1) {
      if (pat[j] == pat[i - 1]) {
        F[i] = j + 1;
        break;
      }
      if (j == 0) {
        F[i] = 0;
        break;
      }
      j = F[j];
    }
  }
}
vector<int> a[100005];
int KMP(char *pat, char *text, int idx) {
  int match = 0;
  build_F(pat);
  lent = strlen(text);
  int i = 0;
  int j = 0;
  for (;;) {
    if (j == lent) break;
    if (text[j] == pat[i]) {
      i++;
      j++;
      if (i == lenp) {
        match++;
        int st = j - lenp, ed = j - 1;
        a[st].push_back(2 * idx);
        a[ed].push_back(2 * idx + 1);
      }
    } else if (i > 0)
      i = F[i];
    else
      j++;
  }
  return match;
}
int front, rear;
int in[100005];
int main() {
  while (scanf("%s", text) == 1) {
    scanf("%d", &N);
    int len = strlen(text);
    for (int i = 0; i <= len; i++) a[i].clear();
    for (int i = 0; i < N; i++) {
      scanf("%s", pat);
      KMP(pat, text, i);
    }
    int ans = 0, idx = 0;
    front = rear = 0;
    memset(in, 0, sizeof(in));
    for (int i = 0; i < len; i++) {
      int L = a[i].size();
      for (int j = 0; j < L; j++)
        if (!(a[i][j] & 1)) in[a[i][j] / 2]++;
      for (int j = 0; j < L; j++)
        if (a[i][j] & 1) {
          while (front <= i && in[a[i][j] / 2]) {
            int ll = a[front].size();
            for (int k = 0; k < ll; k++)
              if (!(a[front][k] & 1)) in[a[front][k] / 2]--;
            front++;
          }
        }
      if (ans < i - front + 1) {
        ans = i - front + 1;
        idx = front;
      }
    }
    printf("%d %d\n", ans, idx);
  }
  return 0;
}
