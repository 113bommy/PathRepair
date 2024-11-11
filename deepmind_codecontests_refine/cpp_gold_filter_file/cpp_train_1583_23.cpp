#include <bits/stdc++.h>
bool comp[1001], mark[1001];
char in[1001], out[1001];
int vet[26], primes[1001], pc, len;
void sieve() {
  int lim = sqrt(1001) + 1;
  for (int i = 2; i <= lim; ++i) {
    if (comp[i]) continue;
    for (int j = i * i; j < 1001; j += i) comp[j] = true;
  }
  for (int i = 2; i < 1001; ++i)
    if (!comp[i]) primes[pc++] = i;
}
int main() {
  scanf("%s", in);
  sieve();
  for (int i = 0; in[i]; ++i, ++len) vet[in[i] - 'a']++;
  if (len == 1) {
    printf("YES\n");
    printf("%s\n", in);
  } else {
    int fp;
    for (int i = 1; i < pc; ++i) {
      if (primes[i] * 2 - 1 >= len) {
        fp = i - 1;
        break;
      }
    }
    int max = 0;
    char c;
    for (int i = 0; i < 26; ++i) {
      if (vet[i] > max) {
        c = i;
        max = vet[i];
      }
    }
    int nc = 0;
    for (int i = 0; i <= fp; ++i) {
      for (int j = 1; j * primes[i] - 1 < len; ++j) {
        if (!mark[j * primes[i] - 1]) {
          mark[j * primes[i] - 1] = 1;
          out[j * primes[i] - 1] = c + 'a';
          vet[c]--;
          ++nc;
        }
      }
    }
    if (max >= nc) {
      printf("YES\n");
      char d = 0;
      for (int i = 0; i < len; ++i) {
        if (mark[i]) continue;
        while (!vet[d]) ++d;
        if (vet[d]) {
          vet[d]--;
          out[i] = d + 'a';
        }
      }
      out[len] = '\0';
      printf("%s\n", out);
    } else {
      printf("NO\n");
    }
  }
}
