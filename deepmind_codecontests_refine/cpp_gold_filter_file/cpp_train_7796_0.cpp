#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){
while(1){
int a,b,c,q,w,e[301],l[1000][4],n;
cin>>a>>b>>c;
if(a==0&&b==0&&c==0)break;
cin>>n;
for(q=1;q<=a+b+c;q++)e[q]=2;
for(q=0;q<n;q++){
cin>>l[q][0]>>l[q][1]>>l[q][2]>>l[q][3];
if(l[q][3]==1){
e[l[q][0]]=1;e[l[q][1]]=1;e[l[q][2]]=1;
}
}
for(q=0;q<n;q++){
for(w=0;w<n;w++){
if(l[w][3]==0&&e[l[w][0]]==1&&e[l[w][1]]==1)e[l[w][2]]=0;
if(l[w][3]==0&&e[l[w][2]]==1&&e[l[w][1]]==1)e[l[w][0]]=0;
if(l[w][3]==0&&e[l[w][0]]==1&&e[l[w][2]]==1)e[l[w][1]]=0;
}
}
for(q=1;q<=a+b+c;q++)cout<<e[q]<<endl;
}
return 0;
}

