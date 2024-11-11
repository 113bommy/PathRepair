#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
  return os << "(" << a.first << ", " << a.second << ")";
};
template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cerr << *i << " ";
  cerr << endl;
}
template <class T>
bool chmin(T &t, const T &f) {
  if (t > f) {
    t = f;
    return true;
  }
  return false;
}
template <class T>
bool chmax(T &t, const T &f) {
  if (t < f) {
    t = f;
    return true;
  }
  return false;
}
constexpr int MAX_N = 1010;
constexpr int MAX_K = 1010;
constexpr int MUL[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 2, 3},
    {0, 2, 3, 1},
    {0, 3, 1, 2},
};
int N, K;
char typ[MAX_K][10], mix[MAX_K][10];
int M[MAX_K], J[MAX_K][MAX_N];
int fs[MAX_N], gs[MAX_N];
int aLen;
vector<bitset<2 * MAX_N>> a;
int main() {
  for (; ~scanf("%d%d", &N, &K);) {
    for (int k = 0; k < K; ++k) {
      scanf("%s%d", typ[k], &M[k]);
      for (int m = 0; m < M[k]; ++m) {
        scanf("%d", &J[k][m]);
        --J[k][m];
      }
      if (!strcmp(typ[k], "mix")) {
        scanf("%s", mix[k]);
      }
    }
    fill(fs, fs + N, 1);
    fill(gs, gs + N, 0);
    aLen = 0;
    a.assign(2 * K, bitset<2 * MAX_N>());
    for (int k = 0; k < K; ++k) {
      if (!strcmp(typ[k], "mix")) {
        const int num = string("WRYB").find(mix[k]);
        for (int m = 0; m < M[k]; ++m) {
          const int i = J[k][m];
          switch (gs[i]) {
            case 0: {
              const int p = (fs[i] >> 0) & 1;
              const int q = (fs[i] >> 1) & 1;
              a[aLen + 0][i << 1 | 0] = p;
              a[aLen + 0][i << 1 | 1] = q;
              a[aLen + 1][i << 1 | 0] = q;
              a[aLen + 1][i << 1 | 1] = p ^ q;
            } break;
            case 1: {
              const int p = (fs[i] >> 0) & 1;
              const int q = (fs[i] >> 1) & 1;
              a[aLen + 0][i << 1 | 0] = p;
              a[aLen + 0][i << 1 | 1] = p ^ q;
              a[aLen + 1][i << 1 | 0] = q;
              a[aLen + 1][i << 1 | 1] = p;
            } break;
            default:
              assert(false);
          }
        }
        a[aLen + 0][N << 1] = (num >> 0) & 1;
        a[aLen + 1][N << 1] = (num >> 1) & 1;
        aLen += 2;
      } else if (!strcmp(typ[k], "RY")) {
        for (int m = 0; m < M[k]; ++m) {
          const int i = J[k][m];
          fs[i] = MUL[2][MUL[fs[i]][fs[i]]];
          gs[i] ^= 1;
        }
      } else if (!strcmp(typ[k], "RB")) {
        for (int m = 0; m < M[k]; ++m) {
          const int i = J[k][m];
          fs[i] = MUL[3][MUL[fs[i]][fs[i]]];
          gs[i] ^= 1;
        }
      } else if (!strcmp(typ[k], "YB")) {
        for (int m = 0; m < M[k]; ++m) {
          const int i = J[k][m];
          fs[i] = MUL[1][MUL[fs[i]][fs[i]]];
          gs[i] ^= 1;
        }
      } else {
        assert(false);
      }
    }
    a.resize(aLen);
    int r = 0;
    vector<int> hs;
    for (int h = 0; h < N << 1; ++h) {
      for (int i = r; i < aLen; ++i) {
        if (a[i][h]) {
          swap(a[r], a[i]);
          break;
        }
      }
      if (a[r][h]) {
        for (int i = r + 1; i < aLen; ++i) {
          if (a[i][h]) {
            a[i] ^= a[r];
          }
        }
        ++r;
        hs.push_back(h);
      }
    }
    bool ok = true;
    for (int i = r; i < aLen; ++i) {
      ok = ok && !a[i][N << 1];
    }
    if (ok) {
      bitset<2 * MAX_N> sol;
      for (int i = r; i--;) {
        sol[hs[i]] = (int)a[i][N << 1] ^ ((a[i] & sol).count() & 1);
      }
      puts("YES");
      for (int i = 0; i < N; ++i) {
        putchar(".RYB"[(int)sol[i << 1 | 0] << 0 | (int)sol[i << 1 | 1] << 1]);
      }
      puts("");
    } else {
      puts("NO");
    }
  }
  return 0;
}
