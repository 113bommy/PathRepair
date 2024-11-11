#include <bits/stdc++.h>
using namespace std;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
int main() {
  int n;
  scanf("%d", &n);
  string S;
  cin >> S;
  int out[5] = {0};
  if (n == 24) {
    if (S[0] == '0' || S[0] == '1') {
      out[0] = S[0] - '0';
      out[1] = S[1] - '0';
    } else if (S[0] == '2' && (int)S[1] - '0' <= 3) {
      out[0] = S[0] - '0';
      out[1] = S[1] - '0';
    } else {
      out[0] = 0;
      out[1] = S[1] - '0';
    }
    if ((int)S[3] - '0' > 5) {
      out[2] = 5;
      out[3] = S[4] - '0';
    } else {
      out[2] = S[3] - '0';
      out[3] = S[4] - '0';
    }
    printf("%d%d:%d%d", out[0], out[1], out[2], out[3]);
  } else {
    if (S[0] == '0') {
      out[0] = 0;
      if ((int)S[1] - '0' > 0)
        out[1] = S[1] - '0';
      else
        out[1] = 1;
    } else if (S[0] == '1' && (int)S[1] - '0' <= 2) {
      out[0] = 1;
      out[1] = S[1] - '0';
    } else if ((int)S[0] - '0' > 1 && S[1] == '0') {
      out[0] = 1;
      out[1] = 0;
    } else {
      out[0] = 0;
      out[1] = S[1] - '0';
    }
    if ((int)S[3] - '0' > 5) {
      out[2] = 5;
      out[3] = S[4] - '0';
    } else {
      out[2] = S[3] - '0';
      out[3] = S[4] - '0';
    }
    printf("%d%d:%d%d", out[0], out[1], out[2], out[3]);
  }
  return 0;
}
