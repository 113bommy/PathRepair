#include<bits/stdc++.h>
using namespace std;
int main(){
	int N, a, b;
	cin >> N >> a >> b;
	if(abs(N - a) < abs(N - b)){
		cout << "A";
	} else {
		cout << "B";
	}
}