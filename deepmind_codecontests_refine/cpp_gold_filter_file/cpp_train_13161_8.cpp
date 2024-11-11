#include <bits/stdc++.h>
using namespace std;
const int P = int(1e9) + 7;
const int MAX_N = int(1e6) + 10;
int n;
char a[MAX_N], b[MAX_N];
unsigned long long pows[MAX_N], pa[MAX_N], sum;
int main() {
  gets(a + 1);
  gets(b + 1);
  n = strlen(b + 1);
  pows[0] = 1;
  for (int i = 1; i <= n; i++) {
    pows[i] = pows[i - 1] * P;
    sum = sum * P + b[i];
    pa[i] = pa[i - 1] * P + a[i];
  }
  pa[n + 1] = pa[n] * P + a[n + 1];
  vector<int> v;
  n++;
  for (int i = 1; i <= n; i++) {
    if (pa[i - 1] * pows[n - i] + pa[n] - pa[i] * pows[n - i] == sum) {
      v.push_back(i);
    }
  }
  if (!v.empty()) {
    printf("%d\n", (int)v.size());
    for (int i = 0; i < (int)v.size(); i++) {
      printf("%d%c", v[i], i < (int)v.size() - 1 ? ' ' : '\n');
    }
  } else {
    puts("0");
  }
}
