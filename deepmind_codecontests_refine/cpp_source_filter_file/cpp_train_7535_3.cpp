#include <bits/stdc++.h>
using namespace std;
const unsigned long long x = 7;
unsigned long long X[60000];
int Ql[20], Qr[20];
char str[60000], s[60000];
int N;
map<unsigned long long, int> T[20];
map<unsigned long long, bool> A;
void add(int index, unsigned long long H) { T[index][H] = T[index][H] + 1; }
void CalcHashes(char s[], int index) {
  unsigned long long H;
  int i, j, L = strlen(s);
  for (i = 1; i <= L; i++) {
    H = 0;
    for (j = 0; j < i; j++) H += X[i - j - 1] * (s[j] - 'a' + 1);
    add(index, H);
    for (j = i; j < L; j++) {
      H = (H - X[i - 1] * (s[j - i] - 'a' + 1)) * x + (s[j] - 'a' + 1);
      add(index, H);
    }
  }
}
int answer;
void check(unsigned long long H) {
  if (A[H]) return;
  A[H] = true;
  int i, t;
  bool v = true;
  for (i = 0; i < N && v; i++) {
    t = T[i][H];
    if (t < Ql[i] || Qr[i] < t) v = false;
  }
  if (v) answer++;
}
int main() {
  unsigned long long H;
  int i, j, L;
  for (X[0] = 1, i = 1; i <= 60000; i++) X[i] = X[i - 1] * x;
  scanf("%s", str);
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%s%d%d", &s, &Ql[i], &Qr[i]);
    CalcHashes(s, i);
  }
  L = strlen(str);
  for (i = 1; i <= L; i++) {
    H = 0;
    for (j = 0; j < i; j++) H += X[i - j - 1] * (str[j] - 'a' + 1);
    check(H);
    for (j = i; j < L; j++) {
      H = (H - X[i - 1] * (str[j - i] - 'a' + 1)) * x + (str[j] - 'a' + 1);
      check(H);
    }
  }
  printf("%d", answer);
  return 0;
}
