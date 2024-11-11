#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
int nxt[400005], A[400005], store[400005], at[400005];
set<int> Set;
set<pair<long long, long long> > Cur;
int main() {
  int n = getnum(), k = getnum(), ans = 0;
  for (int i = 1; i <= n; i++) A[i] = getnum();
  for (int i = n; i >= 1; i--) {
    if (store[A[i]] != 0)
      nxt[i] = store[A[i]];
    else
      nxt[i] = n + 1;
    store[A[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (Set.find(A[i]) == Set.end()) {
      ans++;
      if (Set.size() == k) {
        auto it = Cur.end();
        it--;
        Set.erase(it->second);
        Cur.erase(it);
      }
      Set.insert(A[i]);
      Cur.insert({nxt[i], A[i]});
      at[A[i]] = i;
    } else {
      Cur.erase({nxt[at[A[i]]], A[i]});
      Cur.insert({nxt[i], A[i]});
      at[A[i]] = i;
    }
  }
  cout << ans << endl;
}
