#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y;
	cin >> x >> y;
	if(y%2 == 0 && x*2<=y && x*4>=y){
		cout << "Yes";
	else {
		cout << "No";
	}
}