#include<bits/stdc++.h>
using namespace std;
int main(){
string a,b;int co=0;
cin>>a>>b;
for(int i=0;i<=2;i++)
    if(a[i]==b[i])
    co++;
cout<<co;
}
