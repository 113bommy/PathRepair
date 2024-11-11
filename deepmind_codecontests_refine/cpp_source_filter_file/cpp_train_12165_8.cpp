#include <bits/stdc++.h>
using namespace std;

long long v[100000]
 
int main() {
	
	long long n,k;
	
	cin >> n >> k;
	
	for(int i = 0;i < n;i++){
		
		long long a,b;
		
		cin >> a >> b;
		
		v[a - 1] += b;
		
	}
	
	for(int i = 0;i < 100000;i++){
		
		if(v[i] >= k){
			cout << i + 1 << endl;
			return 0;
		}
		
		k -= v[i];
		
	}
	
	return 0;
}