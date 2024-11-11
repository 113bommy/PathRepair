#include<iostream>
using namespace std;
int main() {
	int sum = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int a; cin >> a;
		if (a % 2 == 1)sum++;
	}
	if (sum % 2 == 1)cout << "NO\n"; else cout << "YES\n";
}