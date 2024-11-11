#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456,268435456")
using namespace std;
int pr[] = {2, 3, 5, 7, 11};
vector<long long> v1;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 5; i++) {
    v1.push_back(pr[i]);
    for (int j = 0; j < v1.size(); j++)
      if (v1[j] * pr[i] <= n * n * 2) v1.push_back(v1[j] * pr[i]);
  }
  for (int i = v1.size() - n; i < v1.size(); i++) printf(" %d", v1[i]);
  return 0;
}
