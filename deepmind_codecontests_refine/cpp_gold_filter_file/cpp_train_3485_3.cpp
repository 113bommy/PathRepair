#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 7;
int n, m, k, A[N], Ans[N], Ret, Opt[N];
vector<pair<int, int> > E[N];
struct YYZ {
  double w;
  int id;
  friend bool operator<(YYZ A, YYZ B) {
    return A.w == B.w ? A.id > B.id : A.w < B.w;
  }
};
priority_queue<YYZ> Q;
pair<int, int> to[N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1), iLimit = (n); i <= iLimit; (++(i))) scanf("%d", A + i);
  int opt, id, val;
  for (int i = (1), iLimit = (m); i <= iLimit; (++(i))) {
    scanf("%d%d%d", &opt, &id, &val), Opt[i] = opt;
    if (opt == 3)
      Q.push((YYZ){(double)val, i});
    else if (opt == 1)
      to[id] = max(to[id], make_pair(val, i));
    else
      E[id].push_back(make_pair(val, i));
  }
  for (int i = (1), iLimit = (n); i <= iLimit; (++(i)))
    if (A[i] < to[i].first)
      E[i].push_back(make_pair(to[i].first - A[i], to[i].second));
  for (int i = (1), iLimit = (n); i <= iLimit; (++(i)))
    sort(E[i].begin(), E[i].end(),
         [](pair<int, int> A, pair<int, int> B) { return A.first > B.first; });
  for (int i = (1), iLimit = (n); i <= iLimit; (++(i))) {
    long long Last = A[i], Now;
    for (auto x : E[i]) {
      Now = Last + x.first;
      Q.push((YYZ){1.0 * Now / Last, x.second});
      Last = Now;
      ;
    }
  }
  for (int i = (1), iLimit = (k); i <= iLimit; (++(i))) {
    if (Q.empty()) break;
    Ans[(++(Ret))] = Q.top().id;
    Q.pop();
  }
  printf("%d\n", Ret);
  if (Ret)
    sort(Ans + 1, Ans + 1 + Ret, [](int A, int B) { return Opt[A] < Opt[B]; });
  for (int i = (1), iLimit = (Ret); i <= iLimit; (++(i))) printf("%d ", Ans[i]);
  return 0;
}
