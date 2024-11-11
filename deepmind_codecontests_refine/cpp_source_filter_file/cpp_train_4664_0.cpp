#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y;
	cin >> x >> y;
	int k = 0;
	if(x <= 3)
	{
		k = (4 - x) * 100000;
	}
	if(y <= 3)
	{
		k += (4 - y) * 100000;
	}
	if(x + y = 2)
	{
		k += 400000;
	}
	cout << k << endl;
}
