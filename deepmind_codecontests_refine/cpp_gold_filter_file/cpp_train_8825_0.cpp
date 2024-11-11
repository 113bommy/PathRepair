#include<bits/stdc++.h>

using namespace std;

int main() { 
	double a,b;
	cin>>a>>b;
	for(double i=1.0;i<=1010.0;i+=1.0){
		if(int (i*0.08)==a&&int (i*0.1)==b){
			cout<<i;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}