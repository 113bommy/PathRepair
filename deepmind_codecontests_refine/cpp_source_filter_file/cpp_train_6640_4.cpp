#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin >> n;
	bool t=true;
	for(int i=0;i<n;i++){
		int a;cin >> a;
		if(!(a&1)){
			if(a%3!=0 && a%5!=0)
				t=false
		}
	}
	if(t)cout << "DENIED\n";
	else cout << "APPROVED\n";
}