#include<iostream>
using namespace std;
 
main(){
	str S;
	cin >> S;
	int L = S.size();
	cout << S[0] << L-2 << S[L-1] << endl;
}