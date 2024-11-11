#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	vector<int> h(n);

	int mxh = 0;
	string ans = "Yes";

	for(int i=0; i<n; i++){
		cin >> h[i];

		if(h[i]>mxh){
			mxh = h[i];
		}

		if(h[i]<mxh-1){
			ans = "No";
		}
	}

	cout << ans << endl;
}