#include<bits/stdc++.h>

using namespace std;

int main(){
	
	long long a,b;
	
	cin>>a>>b;
	
	cout<<min(a%b,b - (a%b))<<"\n";
	
	return 0;
}
