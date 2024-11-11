#include<iostream>

using namespace std;
typedef long long ll
int main(){
ll a,b,c, k;
cin>>a>>b>>c>>k;
int ret = k%2==0? a-b : b-a;
cout<<ret<<endl;
return 0;
}