#include <bits/stdc++.h>
using namespace std;

int main() {
	int c1,c2,c3,c4,c5,c6,c7,c8,c9;
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6 >> c7 >> c8 >> c9;
	string k = "No";
	if(c1 == c4 + c3 - c6 &&
	   c2 == c5 + c3 - c6 &&
	   c8 == c5 + c7 - c4 &&
	   c9 == c6 + c7 - c4)
	{
		k = "Yes";
	}
	cout << k << endl;
}
