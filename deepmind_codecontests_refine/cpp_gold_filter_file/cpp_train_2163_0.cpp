#include<iostream>
#include<vector>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long> A(N),B(N+1,0);
  int i;
  for(i=0;i<N;i++) {
    cin >> A[i];
    B[i+1] = (B[i] + A[i])%1000000007;
  }
  long long ans = 0;
  for(i=1;i<N;i++)ans = (ans + A[i]*B[i]%1000000007)%1000000007;
  cout << ans << endl;
}