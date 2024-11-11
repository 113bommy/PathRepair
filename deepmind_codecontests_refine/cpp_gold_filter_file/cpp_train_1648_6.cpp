#include <bits/stdc++.h>
using namespace std;

int main(){
	string S, T;
	cin >> S >> T;
	S = S + S;
	if(S.find(T) != -1) cout << "Yes" << endl;
	else cout << "No" << endl;
}