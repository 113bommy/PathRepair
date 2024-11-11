#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int A,B,C;
	cin >> A >> B >> C;
	int K;
	cin >> K;
	string ans = "No";
	for(int i=0; i<K; i++){
		if(A<B*pow(2,i) && B*pow(2,i)<C*pow(2,(K-i)))
			ans = "Yes";
	}
	cout << ans << endl;
}