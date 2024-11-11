#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;
typedef long long ll; 
 
int main(void){
	
	int A[5], time = 0, mi = 10;
	
	for(int i=0; i<5; i++){
		cin >> A[i];
		if(A[i]%10)
			mi = min(mi, A[i]%10);
		time += ceil(A[i]/10.0) * 10;
	}
	
	cout << time + mi - 10;
	
	return 0;
}