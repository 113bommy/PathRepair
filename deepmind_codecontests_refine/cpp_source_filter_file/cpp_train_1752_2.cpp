#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
long long k;
cin>>a>>b>>c>>k;
cout<<(k&1)?b-a:a-b<<endl;
return 0;
}