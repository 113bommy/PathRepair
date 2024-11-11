#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,M=0,ans=0; cin >> N;
	for(int i = 0 , i < N ; i++){
		int p; cin >> p;
		ans += p;
		M = max(M,p);
	}
	cout << ans - M/2 << endl;
}