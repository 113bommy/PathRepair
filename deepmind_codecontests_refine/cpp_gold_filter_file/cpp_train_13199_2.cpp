#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin >> n;
	for(int i = sqrt(n); i>=0; i--) {
		if(!(n % i)) {
			cout << i-1+(n/i-1);
			break;
		}
	}
}