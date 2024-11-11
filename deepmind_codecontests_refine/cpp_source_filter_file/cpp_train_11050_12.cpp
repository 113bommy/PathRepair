#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;
const unsigned long long P = 31;
unsigned long long Hash[maxn], bin[maxn];
void prework() {
  int N = 2005;
  bin[0] = 1;
  for (int i = 1; i <= N; i++) bin[i] = bin[i - 1] * P;
}
inline unsigned long long getsub(int l, int r) {
  return Hash[r] - Hash[l - 1] * bin[r - l + 1];
}
char sta[maxn], stb[maxn], text[maxn];
int LEN;
int a[maxn], b[maxn];
int prea[maxn], preb[maxn];
int KMP(char *s, int prefix[], int load[], int len) {
  prefix[0] = -1;
  int i, j;
  i = 0, j = -1;
  while (i < len) {
    if (j == -1 || s[i] == s[j])
      prefix[++i] = ++j;
    else
      j = prefix[j];
  }
  int ret = 0;
  i = j = 0;
  while (i < LEN) {
    if (j == len - 1 && text[i] == s[j]) {
      load[++ret] = i - len + 1;
      j = prefix[j];
    } else if (j == -1 || text[i] == s[j])
      i++, j++;
    else
      j = prefix[j];
  }
  return ret;
}
int main() {
  prework();
  scanf("%s%s%s", text, sta, stb);
  LEN = strlen(text);
  int lena = strlen(sta), lenb = strlen(stb);
  int na = KMP(sta, prea, a, lena);
  int nb = KMP(stb, preb, b, lenb);
  vector<unsigned long long> book;
  for (int i = 1; i <= LEN; i++)
    Hash[i] = Hash[i - 1] * P + text[i - 1] - 'a' + 1;
  int last = 1, ans = 0;
  int i = 1, j = 1;
  while (i <= na) {
    j = last;
    while ((a[i] > b[j] || a[i] + lena > b[j] + lenb) && j <= nb) j++;
    last = j;
    while (j <= nb) {
      unsigned long long id = getsub(a[i] + 1, b[j] + lenb);
      book.push_back(id);
      j++;
    }
    i++;
  }
  sort(book.begin(), book.end());
  ans = unique(book.begin(), book.end()) - book.begin();
  book.resize(ans);
  printf("%d  的\n", book.size());
}
