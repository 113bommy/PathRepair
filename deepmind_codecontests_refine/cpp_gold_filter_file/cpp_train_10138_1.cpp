#include <bits/stdc++.h>
using namespace std;
vector<long long> vect(200100);
long long n, x, y, ans[200100][2], visited[200100][2];
long long dfs(long long parent, long long count1) {
  if (parent <= 0 || parent > n)
    return 0;
  else if (parent == 1 || visited[parent][count1 % 2] == 1)
    return -1;
  else if (ans[parent][count1 % 2] != -2)
    return ans[parent][count1 % 2];
  else {
    visited[parent][count1 % 2] = 1;
    long long a;
    if (count1 % 2 == 0)
      a = dfs(parent - vect[parent], count1 + 1);
    else
      a = dfs(parent + vect[parent], count1 + 1);
    if (a != -1)
      ans[parent][count1 % 2] = vect[parent] + a;
    else
      ans[parent][count1 % 2] = -1;
    visited[parent][count1 % 2] = 0;
    return ans[parent][count1 % 2];
  }
}
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) ans[i][0] = ans[i][1] = -2;
  for (int i = 2; i <= n; i++) {
    cin >> vect[i];
  }
  for (int i = 1; i < n; i++) {
    x = 1, y = 0;
    long long a = dfs(i + 1, 0);
    if (a == -1)
      cout << a << "\n";
    else
      cout << i + a << endl;
  }
  return 0;
}
