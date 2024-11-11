#include <bits/stdc++.h>
#pragma gcc optimize("O3")
using namespace std;
const int maxn = 500100;
int len, val[maxn], ok[maxn], sr[maxn], ans[maxn], mst[maxn], mlen;
bool no = false;
struct llist {
  struct node {
    int pos;
    node *next = NULL, *last = NULL;
    node(int i) : pos(i){};
  };
  node *front = NULL, *tail = NULL;
  void push_back(int i) {
    if (ok[i] || i == len + 1) return;
    if (!front) {
      tail = front = new node(i);
    } else {
      tail->next = new node(i);
      tail->next->last = tail;
      tail = tail->next;
    }
    ok[i] = true;
  }
  void push_front(llist b) {
    if (!front) {
      front = b.front;
      tail = b.tail;
    } else if (b.front) {
      front->last = b.tail;
      b.tail->next = front;
      front = b.front;
    }
  }
  void out() {
    for (int i = 1; i <= len; ++i) {
      ans[front->pos] = i;
      front = front->next;
    }
  }
};
llist make(int l, int r) {
  llist res;
  if (no) return res;
  if (l > r) return res;
  for (int now = l; now <= r; now = val[now]) {
    res.push_back(now);
  }
  for (int now = l; now <= r; now = val[now]) {
    if (now + 1 <= val[now] - 1) res.push_front(make(now + 1, val[now] - 1));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> len;
    no = false;
    mlen = 0;
    memset(ok, 0, sizeof(int) * (len + 5));
    memset(sr, 0, sizeof(int) * (len + 5));
    for (int i = 1; i <= len; ++i) cin >> val[i];
    for (int i = 1; i <= len; ++i)
      if (val[i] == -1) val[i] = i + 1;
    for (int i = 1; i <= len and !no; ++i) {
      if (i == mst[mlen]) --mlen;
      if (mlen and mst[mlen] < val[i])
        no = true;
      else if (mst[mlen] > val[i])
        mst[++mlen] = val[i];
    }
    if (no)
      cout << -1;
    else {
      make(1, len).out();
      for (int i = 1; i <= len; ++i) cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
