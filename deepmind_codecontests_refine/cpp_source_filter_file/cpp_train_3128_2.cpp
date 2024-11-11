#include<bits/stdc++.h>
using namespace std;

int main(){
int n,i,a[10000];

cin>>n;
for(i=1;i<=n;i++){
cin>>a[i];
}
i=n;
for(;;){
if(i=1){cout<<a[i];
break;}
else{cout<<a[i]<<" ";}
i-=1
}

cout<<endl;
return 0;
}
