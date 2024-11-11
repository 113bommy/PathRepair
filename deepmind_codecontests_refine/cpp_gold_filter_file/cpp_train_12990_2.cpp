#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
ll a,b,n; 
int main(){
	cin>>a>>b>>n;
	cout<<a*min(b-1,n)/b;
    return 0;
}