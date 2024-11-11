#include<bits/stec++.h>
using namespace std;
int N,l,r,a=0;
int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>l>>r;
    a=a+r-l+1;
  }
  cout<<a<<endl;
}