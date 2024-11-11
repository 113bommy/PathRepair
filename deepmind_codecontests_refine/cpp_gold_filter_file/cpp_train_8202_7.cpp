#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  cin >> N;
  long long ans = 0;
  for (long long i = 1; i * i <= N; i++){
    if (N % i == 0){
      if (i < N / i - 1){
        ans += N / i - 1;
      }
    }
  }
  cout << ans << endl;
}