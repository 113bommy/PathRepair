#include <bits/stdc++.h>
using namespace std;
int N;
char S[1000100];
long long Left[1000100];
long long Right[1000100];
inline bool letter(char c) { return ('a' <= c && c <= 'z'); }
inline bool number(char c) { return ('0' <= c && c <= '9'); }
int main() {
  scanf("%s", &S[1]);
  N = strlen(&S[1]);
  memset(Left, 0, sizeof(Left));
  memset(Right, 0, sizeof(Right));
  for (int i = 1; i <= N; i++) {
    if (letter(S[i]) || number(S[i]) || S[i] == '_') Left[i] = Left[i - 1];
    if (letter(S[i])) Left[i]++;
  }
  for (int i = N; i >= 1; i--) {
    if (letter(S[i])) Right[i] = Right[i + 1] + 1;
  }
  long long total = 0;
  char prev = '?';
  int loc = -1;
  bool valid = false;
  for (int i = 1; i <= N; i++) {
    if (S[i] == '@') {
      prev = '@';
      loc = i;
      valid = true;
    } else if (S[i] == '_')
      valid = false;
    else if (S[i] == '.') {
      if (prev == '@' && valid && prev + 1 < i)
        total += Left[loc - 1] * Right[i + 1];
      prev = '.';
    }
  }
  cout << total << endl;
  return 0;
}
