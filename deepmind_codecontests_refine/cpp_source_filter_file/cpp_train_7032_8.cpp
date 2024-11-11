#include <bits/stdc++.h>
using namespace std;
long long int pow1(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long temp;
  if (b % 2 == 0) {
    temp = pow1(a, b / 2);
    temp = temp % 1000000007;
    temp = temp * temp;
    temp = temp % 1000000007;
    return temp;
  } else {
    temp = pow1(a, b / 2);
    temp = temp % 1000000007;
    temp = temp * temp;
    temp = temp % 1000000007;
    temp = temp * a;
    temp = temp % 1000000007;
    return temp;
  }
}
long long n;
vector<long long> a[200002];
vector<long long> cycles;
bool visited[200002];
long long to[200002];
long long index1[100002];
void dfs(int in, int num, int father) {
  visited[in] = true;
  long long i, j;
  index1[in] = num;
  for (i = 0; i < int(a[in].size()); i++) {
    if (visited[a[in][i]] && a[in][i] != father) {
      cycles.push_back(num - index1[a[in][i]] + 1);
    } else if (visited[a[in][i]] && a[in][i] == father) {
      if (to[in] == father && to[father] == in) {
        cycles.push_back(num - index1[a[in][i]] + 1);
      }
    }
  }
  for (i = 0; i < int(a[in].size()); i++) {
    if (!visited[a[in][i]] && a[in][i] != father) {
      dfs(a[in][i], num + 1, in);
    }
  }
}
int main() {
  long long i, j;
  scanf("%lld", &n);
  for (i = 0; i < n + 1; i++) {
    visited[i] = false;
    to[i] = -1;
    index1[i] = 0;
  }
  for (i = 0; i < n; i++) {
    long long temp;
    scanf("%lld", &temp);
    temp--;
    to[i] = temp;
    if (to[temp] == i) {
      continue;
    }
    a[i].push_back(temp);
    a[temp].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, 1, -1);
    }
  }
  long long num = 0;
  for (i = 0; i < cycles.size(); i++) {
    num += cycles[i];
  }
  if (num == 0) {
    printf("%lld\n", pow1(2, n));
    return 0;
  }
  long long ans = pow1(2, n - num);
  for (i = 0; i < cycles.size(); i++) {
    ans = ans *
          (((pow1(2, cycles[i]) - 2) % 1000000007 + 1000000007) % 1000000007);
    ans %= 1000000007;
  }
  printf("%lld\n", ans);
  ;
  return 0;
}
