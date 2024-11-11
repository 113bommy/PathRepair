#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
const int MM = 4000;
bool vis[MM];
int a[M], b[M];
int prime[M], prime_size;
map<int, int> Hash_Prime;
int cnt_num_prime[M + MM], cnt_denum_prime[M + MM], div_num_prime[M + MM],
    div_denum_prime[M + MM];
list<int> L[M + MM];
void prime_produce() {
  memset(vis, false, sizeof(vis));
  prime_size = 1;
  prime[prime_size++] = 2;
  for (int i = 3; i < MM; i += 2) {
    if (!vis[i]) {
      prime[prime_size++] = i;
      for (int j = i + i; j < MM; j += i) {
        vis[j] = true;
      }
    }
  }
}
int main() {
  int n, m;
  prime_produce();
  while (~scanf("%d%d", &n, &m)) {
    Hash_Prime.clear();
    for (int i = 0; i < M + MM; i++) L[i].clear();
    memset(cnt_denum_prime, 0, sizeof(cnt_denum_prime));
    memset(cnt_num_prime, 0, sizeof(cnt_num_prime));
    memset(div_num_prime, 0, sizeof(div_num_prime));
    memset(div_denum_prime, 0, sizeof(div_denum_prime));
    int index = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      int temp = a[i];
      for (int j = 1; j < prime_size; j++) {
        if (temp % prime[j] == 0) {
          temp /= prime[j];
          cnt_num_prime[j]++;
          while (temp % prime[j] == 0) {
            cnt_num_prime[j]++;
            temp /= prime[j];
          }
        }
      }
      if (temp > 1) {
        if (Hash_Prime[temp]) {
          L[Hash_Prime[temp]].push_back(i);
        } else {
          Hash_Prime[temp] = index++;
          L[Hash_Prime[temp]].push_back(i);
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &b[i]);
      int temp = b[i];
      for (int j = 1; j < prime_size; j++) {
        if (temp % prime[j] == 0) {
          temp /= prime[j];
          if (cnt_num_prime[j]) {
            cnt_num_prime[j]--;
            div_num_prime[j]++;
            div_denum_prime[j]++;
          }
          while (temp % prime[j] == 0) {
            temp /= prime[j];
            if (cnt_num_prime[j]) {
              cnt_num_prime[j]--;
              div_num_prime[j]++;
              div_denum_prime[j]++;
            }
          }
        }
      }
      if (Hash_Prime[temp]) {
        if (L[Hash_Prime[temp]].size()) {
          int de = L[Hash_Prime[temp]].front();
          L[Hash_Prime[temp]].pop_front();
          b[i] /= temp;
          a[de] /= temp;
        }
      }
    }
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < prime_size; j++) {
        if (a[i] % prime[j] == 0) {
          while (div_num_prime[j] && (a[i] % prime[j] == 0)) {
            a[i] /= prime[j];
            div_num_prime[j]--;
          }
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j < prime_size; j++) {
        if (b[i] % prime[j] == 0) {
          while (div_denum_prime[j] && b[i] % prime[j] == 0) {
            b[i] /= prime[j];
            div_denum_prime[j]--;
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    for (int i = 1; i <= m; i++) {
      printf("%d%c", b[i], i == m ? '\n' : ' ');
    }
  }
  return 0;
}
