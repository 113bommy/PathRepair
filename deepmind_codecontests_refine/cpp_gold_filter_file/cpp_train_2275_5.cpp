#include <iostream>
using namespace std;
int a,n,cnt=0;
int main(){
  cin>>n;
  for(int i=-1;++i-n;){
    cin>>a;
    if(a&1)cnt=cnt?0:1;
  }
  cout<<(cnt?"NO":"YES")<<endl;
}