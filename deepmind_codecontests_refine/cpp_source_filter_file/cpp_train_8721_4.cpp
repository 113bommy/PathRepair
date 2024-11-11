#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,wa=0;
  cin >> N >> M;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin>>A[i];
    sum+=A[i];
  }
  sort(A.begin(),A.end());
  if(A[N-M]*4*M < sum){
    cout<<"No"<<endl;
    return 0;
  }
    cout<<"Yes"<<endl;
}
