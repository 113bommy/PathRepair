#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p = 0;
	cin >> n;
	for(int i = 1; i*(i+1) < 2*n; i++) p = i;
	cout << p+1;
}
