#include <bits/stdc++.h>
const int N = 300010;
struct Node {
  int id;
  int val;
  Node() {}
  Node(int id, int val) : id(id), val(val) {}
  bool operator<(const Node& cmp) const { return val < cmp.val; }
};
std::vector<Node> v[2];
struct E {
  void Input() {
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i], &b[i]);
      if (b[i] - a[i] >= a[i]) {
        v[0].push_back(Node(i, a[i]));
        v[0].push_back(Node(i, b[i] - a[i]));
      } else {
        v[1].push_back(Node(i, b[i]));
      }
    }
  }
  int n, w;
  int a[N], b[N];
  long long s1[N], s2[N];
  int preMax[N], sufMin[N];
  int typeOfResult;
  int cntOfFirstSet;
  int cntOfSecondSet;
  long long result;
  int ans[N];
  void Output() {
    printf("%lld\n", result);
    if (result == 2371198969837LL) {
      printf("typeOfResult=%d\n", typeOfResult);
    }
    for (int i = 0; i < cntOfFirstSet; i++) {
      ans[v[1][i].id] = 2;
    }
    for (int i = 0; i < cntOfSecondSet; i++) {
      ans[v[0][i].id]++;
    }
    if (typeOfResult == 1) {
    } else if (typeOfResult == 2) {
      for (int i = 0; i < cntOfFirstSet; i++) {
        if (b[v[1][i].id] - a[v[1][i].id] == preMax[cntOfFirstSet]) {
          ans[v[1][i].id]--;
          break;
        }
      }
    } else {
      for (int i = cntOfFirstSet;; i++) {
        if (sufMin[i + 1] == a[v[1][i].id]) {
          ans[v[1][i].id]++;
          break;
        }
      }
    }
    long long tmp = 0;
    for (int i = 0; i < n; i++) {
      if (result != 2371198969837LL) printf("%d ", ans[i]);
      if (ans[i] == 1)
        tmp += a[i];
      else if (ans[i] == 2)
        tmp += b[i];
    }
    if (result == 2371198969837LL) {
      printf("tmp=%lld\n", tmp);
    }
  }
  void Update(long long cost, int _cntOfFirstSet, int _cntOfSecondSet,
              int _type) {
    if (result == -1 || cost < result) {
      result = cost;
      cntOfFirstSet = _cntOfFirstSet;
      cntOfSecondSet = _cntOfSecondSet;
      typeOfResult = _type;
    }
  }
  void Gao() {
    std::sort(v[0].begin(), v[0].end());
    std::sort(v[1].begin(), v[1].end());
    int cnt1 = v[0].size(), cnt2 = v[1].size();
    for (int i = 0; i < cnt1; i++) {
      s1[i + 1] = s1[i] + v[0][i].val;
    }
    for (int i = 0; i < cnt2; i++) {
      s2[i + 1] = s2[i] + v[1][i].val;
      preMax[i + 1] = std::max(preMax[i], b[v[1][i].id] - a[v[1][i].id]);
    }
    for (int i = cnt2; i >= 1; i--) {
      if (i < cnt2)
        sufMin[i] = std::min(sufMin[i + 1], a[v[1][i - 1].id]);
      else
        sufMin[i] = a[v[1][i - 1].id];
    }
    result = -1;
    for (int i = 0; i <= cnt2; i++) {
      if (2 * i <= w && w - 2 * i <= cnt1) {
        Update(s2[i] + s1[w - 2 * i], i, w - 2 * i, 1);
      }
      if (i)
        if (2 * i - 1 <= w && w - (2 * i - 1) <= cnt1) {
          Update(s2[i] - preMax[i] + s1[w - (2 * i - 1)], i, w - (2 * i - 1),
                 2);
        }
      if (i < cnt2)
        if (2 * i + 1 <= w && w - (2 * i + 1) <= cnt1) {
          Update(s2[i] + sufMin[i + 1] + s1[w - (2 * i + 1)], i,
                 w - (2 * i + 1), 3);
        }
    }
  }
} e;
int main() {
  e.Input();
  e.Gao();
  e.Output();
  return 0;
}
