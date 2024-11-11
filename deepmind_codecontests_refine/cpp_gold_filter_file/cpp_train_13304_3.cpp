#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,L,R,ans = 2020;
	cin >> L >> R;
	N = R-L;
	for(int i=L; i < L+min(2019,N); i++){
		for(int j=i+1; j <= min(R,i+2019); j++){
			ans = min(((i%2019)*(j%2019)) % 2019,ans);
		}
	}
	cout << ans << endl;
	return 0;
}
