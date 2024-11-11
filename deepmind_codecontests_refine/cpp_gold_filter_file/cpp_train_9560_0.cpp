#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int x = 0;
	for(int i = A;i <= B;i++){
		if(i / 10000 == i % 10 && i / 1000 % 10 == i / 10 % 10){
			x++;
		}
	}
	cout << x << endl;
}