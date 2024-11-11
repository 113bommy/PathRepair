#include <bits/stdc++.h>
using namespace std;
bool visited[1000005];
long long findx[1000005];
void dfs(long long k, long long x, long long p) {
  visited[x] = true;
  long long i = findx[x];
  if (!visited[i]) dfs(k, i, p);
}
int main() {
  long long p, k;
  cin >> p >> k;
  for (int i = 0; i < p; i++) visited[i] = false;
  int group = 0;
  visited[0] = true;
  for (long long i = 1; i < p; i++) findx[(k * i) % p] = i;
  for (long long i = 1; i < p; i++) {
    if (!visited[(k * i) % p]) {
      visited[(k * i) % p] = true;
      dfs(k, i, p);
      group++;
    }
  }
  long long res = 1;
  long long PRIME = pow(10, 9) + 7;
  if (k == 1) group++;
  if (k == 0) group = p;
  while (group--) res = (res * p) % (PRIME);
  cout << res;
}
