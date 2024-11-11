#include <algorithm>
#include <iostream>
#define N 65000
using namespace std;
typedef long long ll;

int main(){
  ll n,p,j[N],a,c;
  while(1){
    cin>>n;
    if(!n) break;
    c=0;
    for(int i=0;i<n;i++) cin>>p,c+=p;
    for(int i=0;i<n-1;i++) cin>>j[i],c+=j[i];
    sort(j,j+n-1);
    a=c;
    for(int i=0;i<n-1;i++) c-=j[i],a=max(a,c*(i+2));
    cout<<a<<endl;
  }
  return 0;
}