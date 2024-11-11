#include <bits/stdc++.h>
using namespace std;
string s;
int m, n;
inline int left(int i) { return 2 * i; }
inline int right(int i) { return 2 * i + 1; }
inline int mid(int left, int right) { return (left + right) / 2; }
vector<int> heap;
vector<int> p;
vector<int> l, r;
struct heap_pos {
  int pos, left, right;
  heap_pos(int pos, int left, int right) : pos(pos), left(left), right(right) {}
  int mid() { return (left + right) / 2; }
  int width() { return right - left + 1; }
  heap_pos goLeft() { return heap_pos(2 * pos, left, mid()); }
  heap_pos goRight() { return heap_pos(2 * pos + 1, mid() + 1, right); }
};
void initHeap(heap_pos hp) {
  heap[hp.pos] = hp.width();
  if (hp.width() > 1) {
    initHeap(hp.goLeft());
    initHeap(hp.goRight());
  }
}
void minusValue(heap_pos hp, int position) {
  while (hp.width() > 1) {
    --heap[hp.pos];
    if (position <= hp.mid()) {
      hp = hp.goLeft();
    } else {
      hp = hp.goRight();
    }
  }
  --heap[hp.pos];
}
int search(heap_pos hp, int value) {
  while (hp.width() > 1) {
    int leftvalue = heap[hp.goLeft().pos];
    if (leftvalue >= value) {
      hp = hp.goLeft();
    } else {
      value -= leftvalue;
      hp = hp.goRight();
    }
  }
  return hp.left;
}
void read() {
  cin >> s;
  cin >> m;
  cin >> n;
  l.resize(n);
  r.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  heap.resize(2 * m);
  p.resize(m + 1);
}
int main() {
  read();
  initHeap(heap_pos(1, 1, m));
  for (int i = n - 1; i >= 0; --i) {
    int from = l[i] - 1;
    for (int j = 0; j < r[i] - l[i] + 1 && r[i] + 1 <= heap[1]; ++j) {
      from += 2;
      if (from > r[i]) from = l[i];
      int a = search(heap_pos(1, 1, m), r[i] + 1);
      minusValue(heap_pos(1, 1, m), a);
      p[a] = search(heap_pos(1, 1, m), from);
    }
  }
  vector<char> out(m + 1);
  int c = 0;
  for (int i = 1; i <= m; ++i) {
    if (p[i] == 0) {
      out[i] = s[c++];
    } else {
      out[i] = out[p[i]];
    }
    cout << out[i];
  }
  cout << endl;
  return 0;
}
