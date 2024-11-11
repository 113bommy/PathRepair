#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,ans=0;
  cin >> N;
  vector<int64_t>A(N);
  vector<int64_t>B(N+1,0);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    B.at(A.at(i))++;
  }
  for(int i=1;i<=N;i++){
    ans+=(B.at(i)*(B.at(i)-1))/2;
  }
  for(int i=0;i<N;i++){
    cout << ans-B.at(A.at(i))+1 << endl;
  }
}