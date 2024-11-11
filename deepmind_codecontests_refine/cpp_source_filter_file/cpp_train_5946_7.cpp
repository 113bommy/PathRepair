#include <bits/stdc++.h>
using namespace std;
struct Query {
  int a, b, index;
  long long ans;
};
bool Cmp(const Query &a, const Query &b) { return a.b < b.b; }
bool CmpInd(const Query &a, const Query &b) { return a.index < b.index; }
int n;
vector<int> w;
void GetDynamic(int b, vector<long long> &ans) {
  for (int i = n - 1; i >= 0; --i) {
    if (i + b >= n)
      ans[i] = w[i];
    else
      ans[i] = (long long)w[i] + ans[i + b];
  }
}
long long NaiveAns(int a, int b) {
  long long ans = 0;
  for (int i = a; i < n; i += b) ans += w[i];
  return ans;
}
int main() {
  cin >> n;
  w.resize(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  int p;
  cin >> p;
  vector<Query> queries(p);
  for (int i = 0; i < p; ++i) {
    cin >> queries[i].a >> queries[i].b;
    queries[i].a--;
    queries[i].index = i;
  }
  sort(queries.begin(), queries.end(), Cmp);
  int c = (int)sqrt((double)n);
  vector<long long> save(n);
  for (int i = 0; i < p; ++i) {
    if (queries[i].b < c) {
      if (i == 0 || (i > 0 && queries[i].b == queries[i - 1].b)) {
        GetDynamic(queries[i].b, save);
      }
      queries[i].ans = save[queries[i].a];
    } else {
      queries[i].ans = NaiveAns(queries[i].a, queries[i].b);
    }
  }
  sort(queries.begin(), queries.end(), CmpInd);
  for (int i = 0; i < p; ++i) {
    cout << queries[i].ans << endl;
  }
  return 0;
}
