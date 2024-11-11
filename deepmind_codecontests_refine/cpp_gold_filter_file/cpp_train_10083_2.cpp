#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, A, B, answer = 0;
  cin >> N >> A >> B;
  int X[N];
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  for (int i = 1; i < N; i++) {
    answer += min(1ll*A*(X[i]-X[i-1]),B);
  }
  cout << answer;
}
