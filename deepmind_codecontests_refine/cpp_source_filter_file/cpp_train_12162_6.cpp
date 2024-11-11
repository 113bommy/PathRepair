#include<bist/stdc++.h>
using namespace std;
int main(){
int a,b,c;
cin>>a>>b>>c;
cout<<max(a,max(b,c))*9+a+b+c<<endl;
return 0;
}