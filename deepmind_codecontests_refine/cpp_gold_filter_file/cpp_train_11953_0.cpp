#include<iostream>
#include<string>
using namespace std;
int main () {
  int N;
  cin >> N;
  string A, B, C;
  cin >> A >> B >> C;
  int ans = 0;
  for (int i = 0; i < N; i ++) {
    int p = 2;
    if (A[i] == B[i]) p --;
    if (B[i] == C[i]) p --;
    if (p && A[i] == C[i]) p --;
    ans += p;
  }
  cout << ans << endl;
}