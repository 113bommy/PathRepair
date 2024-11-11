#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	//n>k k/n 
	double ans=0;
	for(int i = 1;i <= n;i++)
	{
		double t =1.0/n;
		int a=i;
		while(a<k)
		{
			a*=2;
			t/=2;
		}
		ans+=t;
	}
	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}
