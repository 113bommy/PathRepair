#include <bits/stdc++.h>
using namespace std;
int N;
int P[1000006];
int IP[1000006];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> P[i];
    IP[P[i]] = i;
  }
  int min_sw = 0;
  for (int i = 1; i <= N; i++) {
    if (i != P[i]) {
      min_sw++;
      swap(P[i], P[IP[i]]);
      int a = IP[i];
      IP[P[a]] = a;
      IP[P[i]] = i;
    }
  }
  cout << (min_sw % 2 == N % 2 ? "Petr" : "Um_nik");
  return 0;
}
