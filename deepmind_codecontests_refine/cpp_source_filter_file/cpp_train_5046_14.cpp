#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 17;
int N;
int D[MAXN], S[MAXN];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d %d", D + i, S + i);
  queue<int> q;
  for (int i = 0; i < N; ++i)
    if (D[i] == 1) q.push(i);
  set<long long> st;
  vector<pair<int, int>> res;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (D[cur] == 0) break;
    int nxt = S[cur];
    long long hsh1 = (long long)MAXN * cur + nxt;
    long long hsh2 = (long long)MAXN * nxt + cur;
    if (!(st.count(hsh1) || st.count(hsh2))) {
      res.push_back(pair<int, int>(cur, nxt));
      st.insert(hsh1);
      st.insert(hsh2);
    }
    S[nxt] ^= cur;
    --D[nxt];
    if (D[nxt] == 1) q.push(nxt);
  }
  printf("%d\n", (int)res.size());
  for (auto it : res) printf("%d %d\n", it.first, it.second);
  return 0;
}
