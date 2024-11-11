#include <iostream>
using namespace std;
int a[123456];
int main(){
  int n;cin>>n;
for(int i=0;i<n;++i){cin>>a[i];a[i]--;}
int inf = 200000;
int mi=inf;
int pos=0;
for (int i=0;i<inf;++i){
if(pos==1) mi = min(mi, i);
pos=a[pos];
}
cout<<(mi==inf?-1:mi) << endl;
}