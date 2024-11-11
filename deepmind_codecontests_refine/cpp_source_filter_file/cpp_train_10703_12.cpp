#include<bits/stdc++.h>
using namespace std;
int main() {
	int a,s=;
	cin>>a;
	while(a) {
		if(a%10==2) {
            ++s;
        }
		a/=10;
	}
	cout<<s<<'\n';
	return 0;
}