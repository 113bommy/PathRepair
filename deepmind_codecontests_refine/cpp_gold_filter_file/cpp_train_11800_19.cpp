#include <bits/stdc++.h>
using namespace std;
const int inf(1010101010);
int n, k;
struct node_t {
  node_t(char edge, int h) : edge(edge), hier(0), pop(0), h(h) {}
  char edge;
  int hier, pop;
  int h;
  vector<node_t *> child;
};
void ins(node_t *x, char *pos) {
  x->pop++;
  if (!pos[0]) {
    x->hier++;
    return;
  }
  for (__typeof((x->child).end()) it((x->child).begin());
       it != ((x->child).end()); ++it) {
    node_t *y(*it);
    if (y->edge == pos[0]) {
      ins(y, ++pos);
      return;
    }
  }
  x->child.push_back(new node_t(pos[0], x->h + 1)), ins(x->child.back(), ++pos);
}
char bla[2005];
vector<vector<int> > mems;
int new_mem() {
  mems.push_back(vector<int>());
  return ((int)(mems).size()) - 1;
}
inline int tri(int x) { return x * (x - 1) / 2; }
inline void chmax(int &x, int y) { x = max(x, y); }
inline void merge(vector<int> &dst, vector<int> &erbij, int hh) {
  int cnt_bij(((int)(erbij).size()) - 1);
  dst.resize(((int)(dst).size()) + cnt_bij);
  for (int i(((int)(dst).size()) - 1); ~i; i--) {
    for (int bij(0); bij <= cnt_bij && bij <= i; bij++) {
      chmax(dst[i], dst[i - bij] + erbij[bij] +
                        hh * (tri(i) - tri(i - bij) - tri(bij)));
    }
  }
}
int calc(node_t *x) {
  if (x->hier == 0 && ((int)(x->child).size()) == 1) return calc(x->child[0]);
  int pt(new_mem());
  if (((int)(x->child).size()) == 0) {
    mems[pt].resize(x->pop + 1);
    for (int i(0); i <= (x->pop); i++) {
      mems[pt][i] = tri(i) * x->h;
    }
  } else {
    node_t *y0(x->child[0]);
    int y0pos(calc(y0));
    mems[pt].assign((mems[y0pos]).begin(), (mems[y0pos]).end());
    int ander(y0->pop);
    for (__typeof((x->child).end()) it((x->child).begin() + 1);
         it != ((x->child).end()); ++it) {
      node_t *y(*it);
      int ypos(calc(y));
      merge(mems[pt], mems[ypos], x->h);
      ander += y->pop;
    }
    for (int i(ander + 1); i <= (ander + x->hier); i++) {
      mems[pt].push_back(mems[pt][ander] + (tri(i) - tri(ander)) * x->h);
    }
  }
  return pt;
}
void solve() {
  if (!(cin >> n >> k)) exit(0);
  node_t *root(new node_t('-', 0));
  for (int i(0); i < (n); i++) {
    scanf("%s", bla), ins(root, bla);
  }
  int rr(calc(root));
  cout << mems[rr][k] << endl;
}
int main() {
  while (1) solve();
}
