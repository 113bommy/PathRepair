#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
int a[5],s=0;
r(i,5)cin>>a[i];
r(i,5){
if(a[i]<40)s+=40;
else s+=a[i]
}
cout<<s/5<<endl;
}