#include<bits/stdc++.h>
using namespace std;
int main(){
 long N,K;
  cin>>N>>K;
  long a=N % K;
  
  cout<<min(a,K-a)<<endl;
  


 return 0;
}