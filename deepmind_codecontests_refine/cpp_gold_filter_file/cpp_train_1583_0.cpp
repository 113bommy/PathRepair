#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 25, oo = 1e9 + 7;
char s[N], s1[N];
bitset<N> bs;
vector<int> v;
int freq[30], idx, F;
bool f;
void seive() {
  bs.set();
  bs[0] = bs[1] = 0;
  for (int i = 2; i * i < N; i += 1 + (i & 1)) {
    if (bs[i])
      for (int j = i; i * j < N; j++) {
        bs[i * j] = 0;
      }
  }
}
int push(int n) {
  int c = 0;
  for (int i = 2; i <= n; i++) {
    if (bs[i]) {
      v.push_back(i);
      if (i > n / 2) c++;
    }
  }
  return c;
}
void fun(int i) {
  while (true) {
    if (idx >= 26) (idx = F), f = 0;
    if (f && idx == F) idx++;
    if (freq[idx]) {
      s1[i] = idx + 'a';
      freq[idx]--;
      return;
    }
    idx++;
  }
}
int main() {
  seive();
  scanf("%s", s);
  int sl = strlen(s);
  int l = push(sl);
  for (int i = 0; s[i]; i++) {
    int h = s[i] - 'a';
    freq[h]++;
    if (!f && freq[h] >= sl - l - 1) (f = 1), F = h;
  }
  if (!f) {
    printf("NO\n");
    return 0;
  }
  fun(0);
  for (int i = 1; i < sl; i++) {
    if (l && (i + 1) == v[v.size() - l])
      fun(i), l--;
    else
      (s1[i] = F + 'a'), freq[F]--;
  }
  printf("YES\n%s\n", s1);
  return 0;
}
