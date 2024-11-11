#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sm=0,ml=0;
	for(int i=0;i<n;i++)
	{
		int l;
		cin >> l;
		sm += l;
		ml = max(ml,l);
	}
	string k = "Yes";
	if(sm <= 2 * l)
	{
		k = "No";
	}
	cout << k << endl;
	return 0;
}
