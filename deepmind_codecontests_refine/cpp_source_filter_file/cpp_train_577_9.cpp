#include <bits/stdc++.h>
using namespace std;
int h;
int n;
int ar[2000];
int cnt;
void init() {
  scanf("%d", &h);
  n = 1;
  for (int i = 0; i < h; i++) n *= 2;
  n--;
}
vector<int> query(int k) {
  printf("? %d\n", k);
  fflush(stdout);
  int qq;
  scanf("%d", &qq);
  vector<int> v;
  int x;
  for (int i = 0; i < qq; i++) {
    scanf("%d", &x);
    v.push_back(x);
  }
  return v;
}
int stk[10];
void process() {
  int st = 0, nb;
  int ndep = 3;
  st = rand() % n + 1;
  deque<int> dq;
  deque<vector<int> > dq2;
  dq.push_back(st);
  auto v1 = query(st);
  dq2.push_back(v1);
  if (v1.size() == 2) {
    printf("! %d\n", st);
    fflush(stdout);
    return;
  } else if (v1.size() == 1) {
    nb = v1[0];
    stk[1] = st, stk[2] = nb;
  } else {
    int d1 = v1[0];
    int d2 = v1[1];
    int now = d1, pre = st;
    while (true) {
      auto v = query(now);
      dq.push_back(now);
      dq2.push_back(v);
      if (v.size() == 2) {
        printf("! %d\n", now);
        fflush(stdout);
        return;
      } else if (v.size() == 1) {
        break;
      } else {
        int tmp;
        for (int nn : v) {
          if (nn != pre) {
            tmp = nn;
            break;
          }
        }
        pre = now;
        now = tmp;
      }
    }
    now = d2, pre = st;
    while (true) {
      auto v = query(now);
      dq.push_front(now);
      dq2.push_front(v);
      if (v.size() == 2) {
        printf("! %d\n", now);
        fflush(stdout);
        return;
      } else if (v.size() == 1) {
        break;
      } else {
        int tmp;
        for (int nn : v) {
          if (nn != pre) {
            tmp = nn;
            break;
          }
        }
        pre = now;
        now = tmp;
      }
    }
    ndep = dq.size() / 2 + 2;
    for (int i = 1; i < ndep; i++) {
      stk[i] = dq[i - 1];
    }
    for (int nxt : dq2[ndep - 2]) {
      if (nxt != dq[ndep - 3] && nxt != dq[ndep - 1]) {
        stk[ndep++] = nxt;
        break;
      }
    }
  }
  int stc = ndep - 1;
  deque<vector<int> > buf;
  auto v = query(stk[stc]);
  if ((int)v.size() == 2) {
    printf("! %d\n", stk[stc]);
    fflush(stdout);
    return;
  }
  buf.push_back(v);
  for (int i = ndep; i <= h; i++) {
    int nw = stk[i - 1];
    int cur = (int)buf.size();
    int per = stk[stc];
    for (int ct = cur; ct < i - 1; ct++) {
      vector<int> cand;
      if (i == h) {
        for (int nn : buf.front()) {
          if (nn != stk[stc - 1]) cand.push_back(nn);
        }
        int nxt = cand[0];
        stk[++stc] = nxt;
        auto v = query(stk[stc]);
        if ((int)v.size() == 2) {
          printf("! %d\n", stk[stc]);
          fflush(stdout);
          return;
        }
        printf("! %d\n", cand[1]);
        fflush(stdout);
        return;
      } else if (i == h - 1) {
        stc = i - 1;
        for (int nn : buf.front()) {
          if (nn != stk[stc - 1]) cand.push_back(nn);
        }
        stk[++stc] = cand[0];
        auto v = query(stk[stc]);
        vector<int> cand2;
        for (int nn : v) {
          if (nn != stk[stc - 1]) cand2.push_back(nn);
        }
        for (int nxt : cand2) {
          auto v = query(nxt);
          if ((int)v.size() == 2) {
            printf("! %d\n", stk[stc]);
            fflush(stdout);
            return;
          }
        }
        stk[stc] = cand[1];
        v = query(stk[stc]);
        buf.clear();
        buf.push_back(vector<int>());
        buf.push_back(v);
        break;
      } else {
        for (int nn : buf.back()) {
          if (nn != stk[stc - 1]) cand.push_back(nn);
        }
        int nxt = cand[rand() % (int)cand.size()];
        stk[++stc] = nxt;
        auto v = query(stk[stc]);
        if ((int)v.size() == 2) {
          printf("! %d\n", stk[stc]);
          fflush(stdout);
          return;
        }
        buf.push_back(v);
      }
    }
    if (buf.back().size() == 1) {
      stc = i;
      for (int nn : buf[0]) {
        if (nn != stk[stc - 2] && nn != stk[stc]) {
          stk[stc] = nn;
          break;
        }
      }
      buf.clear();
      auto v = query(stk[stc]);
      if ((int)v.size() == 2) {
        printf("! %d\n", stk[stc]);
        fflush(stdout);
        return;
      }
      buf.push_back(v);
    } else {
      buf.pop_front();
    }
  }
  printf("! %d\n", stk[n]);
  fflush(stdout);
}
int main() {
  srand(514513);
  int Cases;
  scanf("%d", &Cases);
  for (int cases = 1; cases <= Cases; cases++) {
    init();
    process();
  }
  return 0;
}
