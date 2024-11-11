#include <bits/stdc++.h>
using namespace std;
int N;
int Prime[100005], cnt2;
bool V[100005];
int Pos[100005];
void Eratostenes() {
  for (int i = 2; i * i <= 2000000000; i++) {
    if (V[i] == 0) {
      Prime[++cnt2] = i;
      Pos[i] = cnt2;
      for (int j = i + i; 1LL * j * j <= 2000000000; j += i) V[j] = 1;
    }
  }
}
int Solve(int nb, int cnt) {
  int ans = nb / Prime[cnt];
  if (ans == 0) return 0;
  for (int i = 1; i < cnt && Prime[i] <= nb / Prime[cnt]; i++)
    ans -= Solve(nb / Prime[cnt], i);
  return ans;
}
bool isPrime(int p) {
  for (int i = 2; i * i <= p; i++) {
    if (p % i == 0) return 0;
  }
  return 1;
}
int main() {
  int A, B, K;
  Eratostenes();
  cin >> A >> B >> K;
  if (isPrime(K) == 0) {
    cout << "0\n";
    return 0;
  }
  if (1LL * K * K > B) {
    if (A <= K && B >= K)
      cout << "1\n";
    else
      cout << "0\n";
    return 0;
  }
  if (V[K] == 1) {
    cout << "0\n";
    return 0;
  }
  cout << Solve(B, Pos[K]) - Solve(A - 1, Pos[K]);
  return 0;
}
