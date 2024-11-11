#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	ll res = 0;
	ll keep = 0;
	for(int i=0; i<n; i++)
	{
		ll a;
		cin >> a;
		if(keep==1 && a>0)
		{
			res++;
			a--;
		}
		res+= a / 2;
		keep = a % 2;
	}
	cout << res << endl;
}