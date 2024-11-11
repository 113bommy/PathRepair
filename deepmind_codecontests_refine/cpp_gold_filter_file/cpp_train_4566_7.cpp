#include <bits/stdc++.h>
using namespace std;
int w, a, b;
int main() {
	cin >> w >> a >> b;
	if(a > b) swap(a, b);
	cout << max(b - a - w, 0) << endl;
	return 0;
}