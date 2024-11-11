#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,A,B;
  cin>>N>>A>>B;
  if(A>B)
    cout<<0<<endl;
  else
    cout<<max((B-A)*(N-2)+1,(int64_t)0)<<endl;
}