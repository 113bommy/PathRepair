#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
int IT_MAX = 1 << 19;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
bool dchk[50050];
int myrand(int M) {
  long long rv = rand() % M;
  rv = (rv * RAND_MAX + rand()) % M;
  rv = (rv * RAND_MAX + rand()) % M;
  rv = (rv * RAND_MAX + rand()) % M;
  return rv;
}
int cnt;
pair<int, int> getv(int x) {
  cnt++;
  printf("? %d\n", x);
  fflush(stdout);
  int t1, t2;
  scanf("%d %d", &t1, &t2);
  return pair<int, int>(t1, t2);
}
int main() {
  srand(time(0));
  int N, st, x, i;
  scanf("%d %d %d", &N, &st, &x);
  vector<pair<int, int> > Vu;
  for (i = 1; i <= min(N, 500); i++) {
    int t;
    do {
      t = myrand(N) + 1;
      if (i == 1) t = st;
    } while (dchk[t]);
    dchk[t] = true;
    pair<int, int> u = getv(t);
    Vu.emplace_back(u.first, t);
  }
  sort((Vu).begin(), (Vu).end());
  int p = lower_bound((Vu).begin(), (Vu).end(), pair<int, int>(x + 1, -1)) -
          Vu.begin();
  p--;
  if (p == -1) {
    printf("! %d\n", st);
    fflush(stdout);
    return 0;
  }
  int t = Vu[p].second;
  while (t != -1 && cnt <= 1990) {
    pair<int, int> u = getv(t);
    if (u.first >= x) {
      printf("! %d\n", u.first);
      fflush(stdout);
      return 0;
    }
    t = u.second;
  }
  printf("! -1\n");
  fflush(stdout);
  return 0;
}
