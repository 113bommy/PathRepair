#include<bist/stdc++.h>
using namespace std;
const int maxn = 200005;
typedef long long LL;

int n;
LL a[maxn], x, y, ans = 1000000000000000000LL;

int main(){
	cin>>n;
	for (int i = 0; i < n; i ++){
		cin>>a[i];
		y += a[i];
	}
	for(int i = 0; i < n - 1; i ++){
		x += a[i];
		y -= a[i];
		ans = min(ans, abs(y - x)) 
	}
	cout << ans <<endl;
	return 0;
}