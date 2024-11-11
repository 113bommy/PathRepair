#include <bits/stdc++.h>
using namespace std;
struct parked {
  int pos;
  int len;
  int next;
  int prev;
};
parked st[1000];
int place[1000] = {0};
int main() {
  int L, b, f;
  int N;
  cin >> L >> b >> f;
  cin >> N;
  st[0].len = 0;
  st[0].pos = -b;
  st[0].prev = -1;
  st[0].next = -1;
  int lc = 1;
  int k = 0;
  for (int i = 0; i < N; ++i) {
    int vid;
    cin >> vid;
    if (vid == 1) {
      k++;
      int len;
      cin >> len;
      bool suc = false;
      int cur_pos = 0;
      while (cur_pos != -1) {
        int next = st[cur_pos].next;
        int gran = 0;
        if (next == -1)
          gran = L;
        else
          gran = st[next].pos - f;
        if (st[cur_pos].pos + st[cur_pos].len + b + len <= gran) {
          st[lc].len = len;
          st[lc].pos = st[cur_pos].pos + st[cur_pos].len + b;
          st[lc].next = st[cur_pos].next;
          st[lc].prev = cur_pos;
          st[cur_pos].next = lc;
          if (next != -1) st[next].prev = lc;
          cout << st[lc].pos << endl;
          place[i] = lc;
          lc++;
          suc = true;
          break;
        }
        cur_pos = next;
      }
      if (!suc) {
        cout << -1 << endl;
      }
    } else {
      int numb;
      cin >> numb;
      int pl = place[numb];
      assert(pl != 0);
      int next = st[pl].next;
      int prev = st[pl].prev;
      if (next != -1) st[next].prev = prev;
      st[prev].next = next;
    }
  }
}
