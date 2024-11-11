#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int pa[N], pb[N], n;
vector<pair<int, int> > cha[N], chb[N];
vector<int> va, vb;
void shift() {
  int temp = va[0];
  for (int i = 1; i < n; i++) {
    va[i - 1] = va[i];
  }
  va[n - 1] = temp;
}
int getAns() {
  int ans = n;
  for (int i = 0; i < n; i++) {
    ans = min(abs(i + 1 - pb[va[i]]), ans);
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    pb[x] = i;
    vb.push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    pa[x] = i;
    va.push_back(x);
  }
  set<pair<int, int> > sa, sb;
  for (int i = 1; i <= n; i++) {
    if (pa[i] > pb[i]) {
      sa.insert(make_pair(pa[i] - pb[i], i));
      cha[pa[i] - pb[i] - 1].push_back(make_pair(pa[i] - pb[i], i));
    } else {
      sb.insert(make_pair(pb[i] - pa[i], i));
      chb[pa[i] - 1].push_back(make_pair(pb[i] - pa[i], i));
    }
  }
  int oa = 0, ob = 0;
  for (int i = 0; i < n; i++) {
    assert(sb.size());
    int ans = n;
    if (sa.size()) {
      ans = min(ans, sa.begin()->first + oa);
    }
    if (sb.size()) {
      ans = min(ans, sb.begin()->first + ob);
    }
    printf("%d\n", ans);
    ob++;
    oa--;
    for (auto &elem : chb[i]) {
      int ind = elem.second;
      assert(sb.count(elem));
      sb.erase(elem);
      if (n == pb[ind]) {
        sb.insert(make_pair(0 - ob, ind));
      } else {
        sa.insert(make_pair(n - pb[ind] - oa, ind));
        cha[i + 1 + n - pb[ind] - 1].push_back(
            make_pair(n - pb[ind] - oa, ind));
      }
    }
    for (auto &elem : cha[i]) {
      int ind = elem.second;
      assert(sa.count(elem));
      sa.erase(elem);
      sb.insert(make_pair(0 - ob, ind));
      chb[i + 1 + pb[ind] - 1].push_back(make_pair(0 - ob, ind));
    }
  }
  return 0;
}
