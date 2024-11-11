#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M;
  cin >>N>>M;
  vector<bool> bad(N+1);
  vector<int> vec(N+2);
  
  for(int i=0;i<M;i++){
    int a;cin>>a;
    bad[a]= true;
  }
  const int mod = 1000000007
  vec[N]=1;
  for(int i=N-1;i>=0;i--){
    if(bad[i]) {
      vec[i]=0;
      continue;
    }
    vec[i] = (vec [i+1]+vec[i+2])%mod;
  }
    cout << vec[0]<<endl;
}
