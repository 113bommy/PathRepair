#include <bits/stdc++.h>
using namespace std;
int N;
long long Ans;
int v[100005];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int a, b;
    cin >> a >> b;
    v[i] = a - b;
    Ans += 1LL * b * (N - 1);
  }
  sort(v + 1, v + 1 + N);
  reverse(v + 1, v + 1 + N);
  for (int i = 1; i <= N; i++) Ans += 1LL * v[i] * (i - 1);
  cout << Ans;
  return 0;
}
