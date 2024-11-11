#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, sta[maxn], top;
int main() {
  scanf("%d", &n);
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    ++top;
    scanf("%d", sta + top);
    while (top > 2 && sta[top] >= sta[top - 1] &&
           sta[top - 1] <= sta[top - 2]) {
      res += min(sta[top - 2], sta[top]);
      sta[top - 1] = sta[top];
      top--;
    }
  }
  sort(sta + 1, sta + top + 1);
  for (int i = 1; i < top - 1; i++) res += sta[i];
  cout << res << endl;
}
