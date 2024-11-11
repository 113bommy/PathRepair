#include<bits/stdc++.h>
using namespace std;
#define evn(a) (a<0?-10:(a)/2*2)
int main(){
  long I,O,J,L;
  cin>>I>>O>>J>>J>>L;
  cout<<max(O+max(evn(I)+evn(J)+evn(L),evn(I-1)+evn(J-1)+evn(L-1)+3),0L)<<"\n";
  return 0;
}