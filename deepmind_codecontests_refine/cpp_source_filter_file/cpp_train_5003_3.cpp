#include<bits/stdc++.h>
using namespace std;

int main(){
int x,y;
cin>>x>>y;

int a[1000][1000]={};
for(int i=1;i<=x;i++){
for(int g=1;g<=y;g++){
cin>>a[i][g];
}}

for(int i=1;i<=x;i++){
for(int g=1;g<=y;g++){
a[i][y+1]+=a[i][g];
}}
for(int i=1;i<=x;i++){
for(int g=1;g<=y;g++){
a[x+1][g]+=a[i][g];
}}
for(int g=1;g<=y;g++){
a[x+1][y+1]+=a[x+1][g]
}

for(int i=1;i<=x+1;i++){
for(int g=1;g<=y+1;g++){
cout<<a[i][g];
if(g<=y){cout<<" ";}
}
cout<<endl;
}


return 0;
}
