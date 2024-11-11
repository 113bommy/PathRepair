#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int ans = a[0];
	for (int i = 1; i < n; i++) {
		ans = ans ^ a[i];
	}
	
	cout << (ans == 0 ? "Yes" : "No") << endl;
}