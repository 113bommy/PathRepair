#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,ans=0;
	cin >> n;
	for(int i=0;i<4;i++){
		if(n%10=2){
			ans++;
		}
		n=n/10;
	}
	cout <<ans << endl;
}