#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A,B,K;
  cin>>A>>B>>K;
  cout<<max(A-K,0LL)<<' '<<max(B-max(0LL,K-A),0)<<endl;
}