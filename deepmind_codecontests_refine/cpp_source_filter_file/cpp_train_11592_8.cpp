#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
int a, b, c, d, i, j, n, m, k;
void brute() {
  int mas[4][4];
  vector<int> num;
  memset((mas), 0, sizeof(mas));
  for (int _n((n * n) - 1), i(0); i <= _n; i++) {
    scanf("%d", &a);
    num.push_back(a);
  }
  sort((num).begin(), (num).end());
  do {
    a = 0;
    for (int _n((n)-1), i(0); i <= _n; i++) {
      for (int _n((n)-1), j(0); j <= _n; j++) {
        mas[i][j] = num[a++];
      }
    }
    int s = -1000000000;
    bool ok = 1;
    for (int _n((n)-1), i(0); i <= _n; i++) {
      int sum = 0;
      for (int _n((n)-1), j(0); j <= _n; j++) sum += mas[i][j];
      if (s == -1000000000)
        s = sum;
      else if (sum != s) {
        ok = 0;
        break;
      }
      sum = 0;
      for (int _n((n)-1), j(0); j <= _n; j++) sum += mas[j][i];
      if (sum != s) {
        ok = 0;
        break;
      }
    }
    int sum = 0;
    for (int _n((n)-1), i(0); i <= _n; i++) sum += mas[i][i];
    if (sum != s) ok = 0;
    sum = 0;
    for (int _n((n)-1), i(0); i <= _n; i++) sum += mas[n - i - 1][i];
    if (sum != s) ok = 0;
    if (ok == 1) {
      printf("%d\n", s);
      for (int _n((n)-1), i(0); i <= _n; i++) {
        for (int _n((n)-1), j(0); j <= _n; j++) {
          if (j) printf(" ");
          printf("%d", mas[i][j]);
        }
        printf("\n");
      }
      exit(0);
    }
  } while (next_permutation((num).begin(), (num).end()));
}
int mas[16];
int sum[2001], num[1 << 16], inv[2001];
vector<int> perm[2001][24];
unordered_map<unsigned long long, unsigned long long> q;
void die(unsigned long long rh, int n1, int n2, int cp1, int cp2, int sum) {
  int p2 = rh % 24;
  rh /= 24;
  int p1 = rh % 24;
  rh /= 24;
  int v2 = rh % k;
  rh /= k;
  int v1 = rh;
  printf("%d\n", sum);
  for (int _n((4) - 1), i(0); i <= _n; i++) {
    vector<int> cur;
    if (!i)
      cur = perm[n1][cp1];
    else if (i == 1)
      cur = perm[n2][cp2];
    else if (i == 2)
      cur = perm[v2][p2];
    else
      cur = perm[v1][p1];
    for (int _n((4) - 1), j(0); j <= _n; j++) {
      if (j) printf(" ");
      printf("%d", cur[j]);
    }
    printf("\n");
  }
  exit(0);
}
int main() {
  srand(25091992);
  scanf("%d", &n);
  if (n <= 3) brute();
  for (int _n((n * n) - 1), i(0); i <= _n; i++) {
    scanf("%d", &mas[i]);
  }
  random_shuffle(mas, mas + n * n);
  for (int _n((1 << (n * n)) - 1), mask(0); mask <= _n; mask++) {
    c = 0;
    d = 0;
    for (int _n((n * n) - 1), i(0); i <= _n; i++)
      if (mask & 1 << i) {
        c += mas[i];
        ++d;
      }
    if (d != 4) continue;
    sum[k] = c;
    inv[k] = mask;
    num[mask] = ++k;
    vector<int> cur;
    for (int _n((n * n) - 1), i(0); i <= _n; i++)
      if (mask & 1 << i) cur.push_back(mas[i]);
    sort((cur).begin(), (cur).end());
    a = 0;
    do {
      perm[k - 1][a++] = cur;
    } while (next_permutation((cur).begin(), (cur).end()));
  }
  int ts = 0;
  for (int _n((n * n) - 1), i(0); i <= _n; i++) ts += mas[i];
  for (int _n((k)-1), i(0); i <= _n; i++) {
    if (ts != sum[i] * 4) continue;
    for (int _n((i)-1), j(0); j <= _n; j++) {
      if (inv[i] & inv[j]) continue;
      if (sum[i] != sum[j]) continue;
      int s = sum[i];
      for (int _n((24) - 1), p1(0); p1 <= _n; p1++) {
        if ((int)((perm[i][p1]).size()) == 0) break;
        const vector<int> &cp1 = perm[i][p1];
        for (int _n((24) - 1), p2(0); p2 <= _n; p2++) {
          if (perm[j][p2].empty()) break;
          const vector<int> &cp2 = perm[j][p2];
          unsigned long long h = 1, rh = 1;
          for (int _n((4) - 1), z(0); z <= _n; z++) {
            h = h * 1234567891 + cp1[z] + cp2[z];
            rh = rh * 1234567891 + s - cp1[z] - cp2[z];
          }
          h = h * 1234567891 + cp1[0] + cp2[1];
          rh = rh * 1234567891 + s - (cp1[3] + cp2[2]);
          h = h * 1234567891 + cp1[3] + cp2[2];
          rh = rh * 1234567891 + s - (cp1[0] + cp2[1]);
          h = h * 1234567891 * (inv[i] | inv[j]);
          rh = rh * 1234567891 * ((~(inv[i] | inv[j])) & ((1 << (n * n)) - 1));
          if (q.count(rh)) {
            die(q[rh], i, j, p1, p2, s);
          }
          unsigned long long val = (long long)k * 24 * 24 * i +
                                   (long long)24 * 24 * j + (long long)24 * p1 +
                                   p2;
          q[h] = val;
        }
      }
    }
  }
}
