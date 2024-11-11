#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a,b;
	cin>>n>>a>>b;
	cout<<max(0,(b-a)*(n-2)+1)<<endl;
}
