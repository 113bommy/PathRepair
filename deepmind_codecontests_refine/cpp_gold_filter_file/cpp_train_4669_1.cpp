#include<bits/stdc++.h>
using namespace std;
int main(){
int n,a,b,mx,mn;
scanf("%d",&n);
scanf("%d %d",&a,&b);
mx=a;mn=b;
for(int i=1;i<n;++i){
scanf("%d %d",&a,&b);
mx=max(a,mx);
mn=min(b,mn);
}
printf("%d\n",mx+mn);
return 0;
}