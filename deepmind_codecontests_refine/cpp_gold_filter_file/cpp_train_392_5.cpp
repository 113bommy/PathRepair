#include<bits/stdc++.h>
using namespace std;

int main(){
int a,d; 
cin>>a;
vector<int> b(a),c;
for(int i=0;i<a;i++)
cin>>b.at(i);
c=b;
sort(b.begin(),b.end());
for(int i=0;i<a;i++){
if(c.at(i)==b.at(a-1)){
d=i;
break;
}
}
for(int i=0;i<a;i++){
if(d==i)
cout<<b.at(a-2)<<endl;
else
cout<<b.at(a-1)<<endl;
}
}