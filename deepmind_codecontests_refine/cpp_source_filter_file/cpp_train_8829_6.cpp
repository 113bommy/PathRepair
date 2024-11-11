#include<bits.stdc++.h>
using namespace std;
int main(){
int64_t N;
  cin>>N;
  vector<int64_t>A(N);
  for(int64_t i=1;i<N;i++){
  int64_t a;
    cin>>a;
    a-=i;
    A.at(i)=a;
  
  }sort(A.begin(),A.end());
  int64_t b=A.at(N/2);
  int64_t ans=0;
  for(int64_t i=0;i<N;i++){
  ans+=abs(A.at(i)-b);
  
  }cout<<ans<<endl;

   return 0;
}