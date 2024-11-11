#include <bits/stdc++.h>
using namespace std;
long long int N, M, K;
long long int A, B;
long long int V[100005];
int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> V[i];
  sort(V, V + N);
  A = V[N - 1];
  B = V[N - 2];
  cout << ((M / (K + 1)) * (K * A + B) + (M % (K + 1)) * A);
}
