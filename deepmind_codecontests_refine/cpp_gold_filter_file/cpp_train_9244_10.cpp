#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,a,b;
  cin>>n>>a;
  for(int i=0;i<4;i++){
    cin>>b;
    if(b<a)
      a=b;
  }
  cout<<(n+a-1)/a+4<<endl;
}
