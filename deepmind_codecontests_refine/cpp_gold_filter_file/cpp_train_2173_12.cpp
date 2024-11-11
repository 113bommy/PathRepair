#include <bits/stdc++.h>
using namespace std;
int main(){
long long n,i,l;
cin>>n>>l;
vector<string>m(n);
for(i=0;i<n;i++){
cin>>m[i];
}
sort(m.begin(),m.end());
for(i=0;i<n;i++){
cout<<m[i];}
cout<<endl;
}





 