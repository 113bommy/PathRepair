#include <bits/stdc++.h>
using namespace std;
long long n, k;
int tothigh;
int anshigh[850000];
vector<int> anslow[10][2];
int id, to[10000000], cnt[10][2][850000];
int dig[10];
void get_high(int bit) {
  int num = 0, i = bit;
  while (i) {
    num = num * 10 + dig[i];
    i--;
  }
  anshigh[tothigh++] = num;
}
void find_high(int bit) {
  for (int i = 0; i <= 9; i++) {
    if (i != dig[bit - 1]) {
      if (bit <= 2 ||
          (bit > 2 && ((i > dig[bit - 1] && dig[bit - 2] > dig[bit - 1]) ||
                       (i < dig[bit - 1] && dig[bit - 2] < dig[bit - 1])))) {
        dig[bit] = i;
        if (i) get_high(bit);
        if (bit < 7) find_high(bit + 1);
      }
    }
  }
}
void get_low() {
  int num = 0, i = 7;
  while (i) {
    num = num * 10 + dig[i];
    i--;
  }
  if (dig[7] < dig[6]) {
    anslow[dig[7]][0].push_back(num);
    if (!to[num % n]) to[num % n] = ++id;
    cnt[dig[7]][0][to[num % n]]++;
  } else {
    anslow[dig[7]][1].push_back(num);
    if (!to[num % n]) to[num % n] = ++id;
    cnt[dig[7]][1][to[num % n]]++;
  }
}
void find_low(int bit) {
  for (int i = 0; i <= 9; i++) {
    if (i != dig[bit - 1]) {
      if (bit <= 2 ||
          (bit > 2 && ((i > dig[bit - 1] && dig[bit - 2] > dig[bit - 1]) ||
                       (i < dig[bit - 1] && dig[bit - 2] < dig[bit - 1])))) {
        dig[bit] = i;
        if (bit == 7)
          get_low();
        else
          find_low(bit + 1);
      }
    }
  }
}
bool check(long long x) {
  int a = x % 10;
  x /= 10;
  int b = x % 10;
  x /= 10;
  while (x) {
    int c = x % 10;
    x /= 10;
    if ((b > a && b > c) || (b < a && b < c))
      ;
    else
      return false;
    a = b;
    b = c;
  }
  return true;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  dig[0] = -1;
  find_high(1);
  find_low(1);
  sort(anshigh, anshigh + tothigh);
  for (int i = 0; i < tothigh; i++) {
    if (anshigh[i] % n == 0) {
      k--;
      if (!k) {
        printf("%d\n", anshigh[i]);
        return 0;
      }
    }
  }
  if (n >= 10000000) {
    for (long long i = n; i <= 100000000000000LL; i += n) {
      if (check(i)) {
        k--;
        if (!k) {
          printf("%I64d\n", i);
          return 0;
        }
      }
    }
  } else
    for (int i = 0; i < tothigh; i++) {
      int r = to[(n - (long long)anshigh[i] * 10000000 % n) % n];
      if (!r) continue;
      if (anshigh[i] < 10) {
        for (int j = 0; j <= 9; j++) {
          if (j == anshigh[i]) continue;
          if (j > anshigh[i]) {
            if (cnt[j][1][r]) {
              if (k > cnt[j][1][r])
                k -= cnt[j][1][r];
              else {
                sort(anslow[j][1].begin(), anslow[j][1].end());
                for (int it = 0; it < anslow[j][1].size(); it++) {
                  if (to[anslow[j][1][it] % n] == r) {
                    k--;
                    if (!k) {
                      printf("%d%07d\n", anshigh[i], anslow[j][1][it]);
                      return 0;
                    }
                  }
                }
              }
            }
          } else {
            if (cnt[j][0][r]) {
              if (k > cnt[j][0][r])
                k -= cnt[j][0][r];
              else {
                sort(anslow[j][0].begin(), anslow[j][0].end());
                for (int it = 0; it < anslow[j][0].size(); it++) {
                  if (to[anslow[j][0][it] % n] == r) {
                    k--;
                    if (!k) {
                      printf("%d%07d\n", anshigh[i], anslow[j][0][it]);
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      } else {
        if (anshigh[i] % 10 > anshigh[i] / 10 % 10) {
          for (int j = 0; j < anshigh[i] % 10; j++) {
            if (cnt[j][0][r]) {
              if (k > cnt[j][0][r])
                k -= cnt[j][0][r];
              else {
                sort(anslow[j][0].begin(), anslow[j][0].end());
                for (int it = 0; it < anslow[j][0].size(); it++) {
                  if (to[anslow[j][0][it] % n] == r) {
                    k--;
                    if (!k) {
                      printf("%d%07d\n", anshigh[i], anslow[j][0][it]);
                      return 0;
                    }
                  }
                }
              }
            }
          }
        } else {
          for (int j = anshigh[i] % 10 + 1; j <= 9; j++) {
            if (cnt[j][1][r]) {
              if (k > cnt[j][1][r])
                k -= cnt[j][1][r];
              else {
                sort(anslow[j][1].begin(), anslow[j][1].end());
                for (int it = 0; it < anslow[j][1].size(); it++) {
                  if (to[anslow[j][1][it] % n] == r) {
                    k--;
                    if (!k) {
                      printf("%d%07d\n", anshigh[i], anslow[j][1][it]);
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  printf("-1\n");
  return 0;
}
