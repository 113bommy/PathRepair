#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int h, w, ans;
	cin >> h >> w;
	if(w==1||h==1) ans = 1;
	else ans = (h*w + 1)/2;
	cout << ans << endl;
}