#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10, mod = 998244353;
long long n, m, k, x, y, op;
long long ans1, ans2, div2;
int limr[MAXN][2], limc[MAXN][2];
int cntL, cntR, cntr[MAXN], cntc[MAXN];
int rcnt1, rcnt2, rcnt0, ccnt1, ccnt2, ccnt0;
map<pair<int, int>, int> color;
long long power(long long a, long long n) {
  if (!n) return 1;
  long long tmp = power(a, n / 2);
  tmp = tmp * tmp % mod;
  if (n & 1) tmp = tmp * a % mod;
  return tmp;
}
void remove(int x, int y) {
  if (color[make_pair(x, y)] == -1) {
    if ((!(y & 1))) {
      limr[x][0]--;
      if (limr[x][0] == 0) {
        if (limr[x][1] == 0) {
          rcnt1--;
          rcnt0++;
        } else {
          rcnt2--;
          rcnt0++;
        }
      }
    } else {
      limr[x][1]--;
      if (limr[x][1] == 0) {
        if (limr[x][0] == 0) {
          rcnt1--;
          rcnt0++;
        } else {
          rcnt2--;
          rcnt0++;
        }
      }
    }
  } else if (color[make_pair(x, y)] == 1) {
    if ((y & 1)) {
      limr[x][0]--;
      if (limr[x][0] == 0) {
        if (limr[x][1] == 0) {
          rcnt1--;
          rcnt0++;
        } else {
          rcnt2--;
          rcnt0++;
        }
      }
    } else {
      limr[x][1]--;
      if (limr[x][1] == 0) {
        if (limr[x][0] == 0) {
          rcnt1--;
          rcnt0++;
        } else {
          rcnt2--;
          rcnt0++;
        }
      }
    }
  }
  if (color[make_pair(x, y)] == -1) {
    if ((!(x & 1))) {
      limc[y][0]--;
      if (limc[y][0] == 0) {
        if (limc[y][1] == 0) {
          ccnt1--;
          ccnt0++;
        } else {
          ccnt2--;
          ccnt0++;
        }
      }
    } else {
      limc[y][1]--;
      if (limc[y][1] == 0) {
        if (limc[y][0] == 0) {
          ccnt1--;
          ccnt0++;
        } else {
          ccnt2--;
          ccnt0++;
        }
      }
    }
  } else if (color[make_pair(x, y)] == 1) {
    if ((x & 1)) {
      limc[y][0]--;
      if (limc[y][0] == 0) {
        if (limc[y][1] == 0) {
          ccnt1--;
          ccnt0++;
        } else {
          ccnt2--;
          ccnt0++;
        }
      }
    } else {
      limc[y][1]--;
      if (limc[y][1] == 0) {
        if (limc[y][0] == 0) {
          ccnt1--;
          ccnt0++;
        } else {
          ccnt2--;
          ccnt0++;
        }
      }
    }
  }
  if (color[make_pair(x, y)] == -1) {
    if ((!((x + y) & 1))) {
      cntL--;
    } else {
      cntR--;
    }
  } else if (color[make_pair(x, y)] == 1) {
    if (((x + y) & 1)) {
      cntL--;
    } else {
      cntR--;
    }
  }
  color[make_pair(x, y)] = 0;
}
void coverzero(int x, int y) {
  remove(x, y);
  if ((!(y & 1))) {
    limr[x][0]++;
    if (limr[x][0] == 1) {
      if (limr[x][1] == 0) {
        rcnt1++;
        rcnt0--;
      } else {
        rcnt2++;
        rcnt0--;
      }
    }
  } else {
    limr[x][1]++;
    if (limr[x][1] == 1) {
      if (limr[x][0] == 0) {
        rcnt1++;
        rcnt0--;
      } else {
        rcnt2++;
        rcnt0--;
      }
    }
  }
  if ((!(x & 1))) {
    limc[y][0]++;
    if (limc[y][0] == 1) {
      if (limc[y][1] == 0) {
        ccnt1++;
        ccnt0--;
      } else {
        ccnt2++;
        ccnt0--;
      }
    }
  } else {
    limc[y][1]++;
    if (limc[y][1] == 1) {
      if (limc[y][0] == 0) {
        ccnt1++;
        ccnt0--;
      } else {
        ccnt2++;
        ccnt0--;
      }
    }
  }
  if ((!((x + y) & 1))) {
    cntL++;
  } else {
    cntR++;
  }
  color[make_pair(x, y)] = -1;
}
void coverone(int x, int y) {
  remove(x, y);
  if ((y & 1)) {
    limr[x][0]++;
    if (limr[x][0] == 1) {
      if (limr[x][1] == 0) {
        rcnt1++;
        rcnt0--;
      } else {
        rcnt2++;
        rcnt0--;
      }
    }
  } else {
    limr[x][1]++;
    if (limr[x][1] == 1) {
      if (limr[x][0] == 0) {
        rcnt1++;
        rcnt0--;
      } else {
        rcnt2++;
        rcnt0--;
      }
    }
  }
  if ((x & 1)) {
    limc[y][0]++;
    if (limc[y][0] == 1) {
      if (limc[y][1] == 0) {
        ccnt1++;
        ccnt0--;
      } else {
        ccnt2++;
        ccnt0--;
      }
    }
  } else {
    limc[y][1]++;
    if (limc[y][1] == 1) {
      if (limc[y][0] == 0) {
        ccnt1++;
        ccnt0--;
      } else {
        ccnt2++;
        ccnt0--;
      }
    }
  }
  if (((x + y) & 1)) {
    cntL++;
  } else {
    cntR++;
  }
  color[make_pair(x, y)] = 1;
}
void calc() {
  long long ret = 0;
  if (!rcnt2) {
    ret += power(2, rcnt0);
  }
  if (!ccnt2) {
    ret += power(2, ccnt0);
  }
  if (cntL == 0) ret--;
  if (cntR == 0) ret--;
  printf("%lld\n", ret % mod);
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  rcnt0 = n;
  ccnt0 = m;
  ans1 = power(2, n);
  ans2 = power(2, m);
  for (int i = (1); i <= (k); i++) {
    scanf("%lld%lld%lld", &x, &y, &op);
    if (op == -1) {
      remove(x, y);
    } else if (op == 0) {
      coverzero(x, y);
    } else {
      coverone(x, y);
    }
    calc();
  }
  return 0;
}
