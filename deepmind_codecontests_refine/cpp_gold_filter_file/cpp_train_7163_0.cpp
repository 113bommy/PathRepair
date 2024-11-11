#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ll n,a,b;
cin>>n>>a>>b;
cout<<min(a,b)<<" "<<max((ll)0,a+b-n);
}
