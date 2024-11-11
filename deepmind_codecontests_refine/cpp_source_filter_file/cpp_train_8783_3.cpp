#include <bits/stdc++.h>
using namespace std;
const int N = 1011110;
int A[N], ans[N];
bool pre[N];
vector<int> s;
int n, T;
void NIE() {
  puts("NO");
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  scanf("%d", &T);
  for (int i = 1, u; i <= T; i++) {
    scanf("%d", &u);
    pre[u] = true;
  }
  for (int i = n; i >= 1; i--) {
    if (pre[i] || s.size() == 0) {
      ans[i] = -A[i];
      s.push_back(A[i]);
    } else {
      if (s.back() == A[i]) {
        s.pop_back();
        ans[i] = A[i];
      } else {
        ans[i] = -A[i];
        s.pop_back();
      }
    }
  }
  if (s.size()) NIE();
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
