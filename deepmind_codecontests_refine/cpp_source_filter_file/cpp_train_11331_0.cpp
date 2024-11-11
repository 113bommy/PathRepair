#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll K; cin >> K;
  int N = 50;
  cout << N << '\n';
  for (int i = 0; i < N; i++) {
    cour << (N+1) * (K / N + (i < K % N)) + (N-1) - K << " \n"[i+1==N];
  }
}