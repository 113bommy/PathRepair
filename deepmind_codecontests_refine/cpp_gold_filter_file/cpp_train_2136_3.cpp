#include <bits/stdc++.h>
using namespace std;
int ctos;
char A[1000005], B[1000005];
vector<int> KMP(string S, string K) {
  vector<int> T(K.size() + 1, -1);
  vector<int> matches;
  if (K.size() == 0) {
    matches.push_back(0);
    return matches;
  }
  for (int i = 1; i <= K.size(); i++) {
    int pos = T[i - 1];
    while (pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
    T[i] = pos + 1;
  }
  int sp = 0;
  int kp = 0;
  while (sp < S.size()) {
    while (kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
    kp++;
    sp++;
    if (sp == S.size() and kp > 0) matches.push_back(sp - K.size());
  }
  return matches;
}
int main() {
  scanf("%d%s%s", &ctos, A, B);
  for (int i = 0; i < ctos - 1; i++) {
    if (A[i] == 'N')
      A[i] = 'S';
    else if (A[i] == 'S')
      A[i] = 'N';
    else if (A[i] == 'E')
      A[i] = 'W';
    else
      A[i] = 'E';
  }
  if (ctos == 2) {
    if (A[0] == B[0]) {
      printf("NO\n");
    } else
      printf("YES\n");
    return 0;
  }
  int x = 0, y = ctos - 2;
  while (x < y) {
    char m = A[x];
    A[x] = A[y];
    A[y] = m;
    ++x;
    --y;
  }
  if (KMP(B, A).size() > 0) {
    printf("NO\n");
  } else
    printf("YES\n");
  return 0;
}
