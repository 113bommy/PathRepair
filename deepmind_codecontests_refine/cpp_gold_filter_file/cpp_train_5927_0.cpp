#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;
#define repn(i,s,n) for (int i=int(s); i < int(n); i++)
#define rep(i,n) repn(i,0,n)
#define repd(i,n) for (int i=int(n)-1; i >= 0; i--)


struct Node {
  int val;  // この区間に足される値
  int min;  // この区間の最小値（valを含む）
  Node() : min(0), val(0) {}
};

#define LC(k) (k*2 + 1)  // 左の子
#define RC(k) (k*2 + 2)  // 右の子

const int INF = INT_MAX;

struct RMQRangeAddSegTree {
  vector<Node> tree;
  int n;
  RMQRangeAddSegTree(int n) : n(n), tree(n*2 - 1) {}  // nは2のべき乗でなければならない

  // 区間[l,r)内の要素にvalを足す
  void addRange(int l, int r, int val) {
    addRange(l, r, 0, 0, n, val);
  }

  // a,b: クエリ対象の範囲[a,b)
  // k: 現在のノードの番号
  // l,r: 現在のノードkの範囲[l,r)
  // val: [a,b)に追加する値
  void addRange(int a, int b, int k, int l, int r, int val) {
    if (r <= a || b <= l) return;
    process_lazy(k);
    if (a <= l && r <= b) {
      tree[k].val += val;
    }
    else {
      addRange(a, b, LC(k), l, (l + r) / 2, val);
      addRange(a, b, RC(k), (l + r) / 2, r, val);
    }
    update_node(k);
  }

  // 遅延評価の実行。根ノード側の更新分を下へ伝搬していく
  void process_lazy(int k) {
    if (k < n - 1 && tree[k].val != 0) {
      tree[LC(k)].val += tree[k].val;
      tree[RC(k)].val += tree[k].val;
      tree[LC(k)].min += tree[k].val;
      tree[RC(k)].min += tree[k].val;
      tree[k].val = 0;
    }
  }

  // 頂点情報の更新。葉ノード側の更新を上へ伝搬していく
  void update_node(int k) {
    if (k >= n - 1) {  // kは葉
      tree[k].min = tree[k].val;
    }
    else {  // kは葉でない
      tree[k].min = tree[k].val + min(tree[LC(k)].min, tree[RC(k)].min);
    }
  }

  // 区間[l,r)内の要素の最小値を返す
  int minRange(int l, int r) {
    return minRange(l, r, 0, 0, n);
  }

  int minRange(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    process_lazy(k);
    if (a <= l && r <= b) return tree[k].min;
    return min(
      minRange(a, b, LC(k), l, (l + r) / 2),
      minRange(a, b, RC(k), (l + r) / 2, r)
    );
  }

  // 区間[x,b)がval以上になる最小のxを返す
  // 存在しなければ-1
  int getLeftGt(int b, int k, int l, int r, int val) {
    if (b <= l) return -2;
    process_lazy(k);
    if (tree[k].min >= val) return l;
    if (r-l == 1) return -1;
    int ret_r = getLeftGt(b, RC(k), (l + r) / 2, r, val);
    if (ret_r > (l + r) / 2 || ret_r == -1) return ret_r;
    int ret_l = getLeftGt(b, LC(k), l, (l + r) / 2, val);
    if (ret_l == -1) return ret_r;
    return ret_l;
  }
};


int main() {
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  int nPow2 = n-1;
  nPow2 |= nPow2 >> 1;
  nPow2 |= nPow2 >> 2;
  nPow2 |= nPow2 >> 4;
  nPow2 |= nPow2 >> 8;
  nPow2 |= nPow2 >> 16;
  nPow2++;

  RMQRangeAddSegTree tree(nPow2);
  string s;
  cin >> s;
  set<int> kets;
  rep(i, n) {
    if (s[i] == '(') {
      tree.addRange(i, n, 1);
    }
    else {
      tree.addRange(i, n, -1);
      kets.insert(i);
    }
  }

  rep(qi, q) {
    int qq;
    cin >> qq;
    qq--;

    if (s[qq] == '(') {
      // '(' to ')'
      s[qq] = ')';
      kets.insert(qq);
      int best = *kets.begin();
      s[best] = '(';
      kets.erase(best);
      cout << best+1 << endl;
      if (best != qq) {
        tree.addRange(qq, n, -2);
        tree.addRange(best, n, 2);
      }
    }
    else {
      // ')' to '('
      s[qq] = '(';
      kets.erase(qq);
      tree.addRange(qq, n, 2);
      int best = tree.getLeftGt(n, 0, 0, nPow2, 2);
      s[best] = ')';
      kets.insert(best);
      cout << best+1 << endl;
      tree.addRange(best, n, -2);
    }
  }
  return 0;
}