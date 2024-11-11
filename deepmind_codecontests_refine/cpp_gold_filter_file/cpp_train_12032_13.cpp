#include <bits/stdc++.h>
using namespace std;
int k, t, state[16];
unordered_map<unsigned long long, long long> M[10];
unsigned long long tobeull(int state[]) {
  int tmp[16] = {
      0,
  };
  unsigned long long ret = 0;
  for (int i = 0; i < 16; i++) tmp[i] = state[i];
  sort(tmp, tmp + 16);
  for (int i = 0; i < 16; i++) {
    ret |= (tmp[i] << (i * 4));
  }
  return ret;
}
long long dp(int len, int state[]) {
  if (len == 0) {
    return 1;
  }
  auto it = M[len].emplace(tobeull(state), 0);
  if (it.second) {
    long long ret = 0;
    for (int i = 0; i < 16; i++) {
      if (state[i] == t) continue;
      state[i]++;
      ret += dp(len - 1, state);
      state[i]--;
    }
    it.first->second = ret;
    return it.first->second;
  } else
    return it.first->second;
}
int main() {
  scanf("%d %d", &k, &t);
  if (k <= 15) {
    printf("%lx", k);
    return 0;
  }
  int mylen = 1;
  state[15]++;
  long long rem = 0;
  while (1) {
    long long key = dp(mylen - 1, state) * (long long)15;
    if (rem + key >= k) {
      break;
    } else
      rem += key;
    ++mylen;
  }
  int st = 1;
  state[15] = 0;
  for (int digit = 1; digit <= mylen; digit++) {
    long long rem = 0;
    if (st == 1) {
      state[15] = 1;
      for (int ite = mylen - 2; ite >= 0; ite--)
        rem += dp(ite, state) * (long long)15;
      state[15] = 0;
    }
    for (int num = st; num < 16; num++) {
      if (state[num] == t) continue;
      state[num]++;
      long long cnt = dp(mylen - digit, state);
      if (rem + cnt >= k) {
        printf("%x", num);
        break;
      } else {
        rem += cnt;
        state[num]--;
      }
    }
    k -= rem;
    st = 0;
  }
}
