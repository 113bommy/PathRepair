#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long l, r, v;
int Q;
struct node {
  int L, R;
  int y;
  long long time, speed, tL, tR, speedR, res, mn;
  node() {
    L = -1, R = -1;
    speed = 0;
    mn = 0;
    y = rng();
  }
} t[100005];
int nodeCnt;
int getNode() { return nodeCnt++; }
int update(int v) {
  if (v == -1) return v;
  t[v].tL = t[v].tR = t[v].time;
  t[v].speedR = t[v].speed;
  long long Mn = 0, Res = 0;
  if (t[v].L != -1) {
    t[v].tL = t[t[v].L].tL;
    Mn = min(Mn, t[t[v].L].mn);
    Mn = min(Mn, t[t[v].L].res +
                     (t[v].time - t[t[v].L].tR) * (long long)t[t[v].L].speedR);
    Res = t[t[v].L].res +
          (t[v].time - t[t[v].L].tR) * (long long)t[t[v].L].speedR;
  }
  if (t[v].R != -1) {
    Mn = min(Mn, Res + (t[t[v].R].tL - t[v].time) * (long long)t[v].speed +
                     t[t[v].R].mn);
    Res += (t[t[v].R].tL - t[v].time) * t[v].speed;
    Res += t[t[v].R].res;
    t[v].speedR = t[t[v].R].speedR;
    t[v].tR = t[t[v].R].tR;
  }
  t[v].mn = Mn;
  t[v].res = Res;
  return v;
}
void split(int v, int T, int &L, int &R) {
  if (v == -1) {
    L = -1, R = -1;
    return;
  }
  if (t[v].time > T) {
    split(t[v].L, T, L, t[v].L);
    R = update(v);
  } else {
    split(t[v].R, T, t[v].R, R);
    L = update(v);
  }
}
int merge(int L, int R) {
  if (L == -1) return R;
  if (R == -1) return L;
  if (t[L].y > t[R].y) {
    t[L].R = merge(t[L].R, R);
    return update(L);
  } else {
    t[R].L = merge(L, t[R].L);
    return update(R);
  }
}
double getAns(int noda) {
  if (v == 0) return l;
  if (noda == -1) {
    return -1;
  }
  if (t[noda].mn <= -v) {
    if (t[noda].L != -1 && t[t[noda].L].mn <= -v) {
      return getAns(t[noda].L);
    }
    long long Res = t[noda].L == -1 ? 0 : t[t[noda].L].res;
    if (t[noda].L != -1) {
      if (Res + (t[noda].time - t[t[noda].L].tR) * t[t[noda].L].speedR <= -v) {
        v += Res;
        return t[t[noda].L].tR + (v * 1.0) / abs(t[t[noda].L].speedR);
      }
      Res += (t[noda].time - t[t[noda].L].tR) * t[t[noda].L].speedR;
    }
    if (t[noda].R != -1) {
      if (Res + (t[t[noda].R].tL - t[noda].time) * t[noda].speed <= -v) {
        v += Res;
        return t[noda].time + (v * 1.0) / abs(t[noda].speed);
      }
      Res += (t[t[noda].R].tL - t[noda].time) * t[noda].speed;
      v += Res;
      return getAns(t[noda].R);
    }
    assert(false);
  } else {
    long long val = t[noda].res + (r - t[noda].tR) * (long long)t[noda].speedR;
    if (val <= -v) {
      v += t[noda].res;
      return t[noda].tR + ((v * 1.0) / abs(t[noda].speedR));
    }
    return -1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  Q = q;
  int root = -1;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int T, s;
      cin >> T >> s;
      int newNode = getNode();
      t[newNode].time = T;
      t[newNode].speed = s;
      update(newNode);
      int L, R;
      split(root, T, L, R);
      root = merge(L, newNode);
      root = merge(root, R);
    } else if (type == 2) {
      int t;
      cin >> t;
      int L, R;
      split(root, t - 1, L, R);
      int L1, R1;
      split(R, t, L1, R1);
      root = merge(L, R1);
    } else {
      cin >> l >> r >> v;
      int L, M, M1, R;
      split(root, l - 1, L, M);
      split(M, r + 1, M1, R);
      cout << fixed << setprecision(10) << getAns(M1) << '\n';
      root = merge(L, M1);
      root = merge(root, R);
    }
  }
}
