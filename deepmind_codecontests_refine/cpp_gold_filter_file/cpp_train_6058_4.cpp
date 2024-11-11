#include <bits/stdc++.h>
using namespace std;
long long a[7005], b[7005];
bool in[7005];
vector<int> going[7005];
int parent[7005];
void disas(int i) {
  for (int next : going[i]) {
    --parent[next];
    if (in[next] && parent[next] == 0) {
      in[next] = false;
      disas(next);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    in[i] = true;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &b[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((a[i] - a[j]) == (a[i] ^ a[j])) {
        going[i].push_back(j);
        ++parent[j];
      }
      if ((a[j] - a[i]) == (a[i] ^ a[j])) {
        going[j].push_back(i);
        ++parent[i];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (in[i] && parent[i] == 0) {
      in[i] = false;
      disas(i);
    }
  }
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    if (in[i]) ret += b[i];
  }
  printf("%lld", ret);
}
