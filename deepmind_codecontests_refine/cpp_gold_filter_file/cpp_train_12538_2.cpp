#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 100005;
int a[N];
int pos[N];
vector<pair<int, int> > ans;
int p[N], prime[N], prime_num;
void fuck_prime() {
  prime_num = 0;
  memset(p, 0, sizeof(p));
  for (int i = 2; i < N - 1; i++) {
    if (!p[i]) {
      prime[++prime_num] = i;
      for (int j = i + i; j < N - 1; j += i) {
        p[j] = 1;
      }
    }
  }
}
void debug() {
  for (int i = 1; i <= n; i++) {
    printf("%d ", pos[a[i]]);
  }
  printf("\n");
}
int main() {
  fuck_prime();
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      pos[a[i]] = i;
    }
    ans.clear();
    for (int i = 1; i <= n; i++) {
      while (pos[i] != i) {
        for (int j = i; j < pos[i]; j++) {
          if (!p[pos[i] - j + 1]) {
            int ni = pos[i], nj = j;
            ans.push_back(make_pair(j, pos[i]));
            pos[i] = nj;
            pos[a[j]] = ni;
            swap(a[ni], a[nj]);
            break;
          }
        }
      }
    }
    cout << ans.size() << endl;
    for (vector<pair<int, int> >::iterator it = ans.begin(); it != ans.end();
         it++) {
      cout << (*it).first << " " << (*it).second << endl;
    }
  }
  return 0;
}
