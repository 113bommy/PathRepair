#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, k, m;
double val = 0;
void Run() {
  cin >> n >> m;
  if (n * m == 1)
    val = 1;
  else
    val = (double)(1.0 / n + (n - 1.0) / n * (m - 1.0) / (m * n - 1.0));
  printf("%7f", val);
}
int main() {
  ios_base::sync_with_stdio(0);
  Run();
  return 0;
}
