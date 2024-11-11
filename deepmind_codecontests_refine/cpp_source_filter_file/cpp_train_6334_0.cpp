#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,a[100005];
long long s[200005];

int main(){
	scanf("%d%d", &n, &m);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	
	long long tot = 0;
	
	for(i = 1; i < n; i++){
		int l = a[i - 1];
		int r = a[i];
		
		if(l <= r){
			s[l + 2]++;
			s[r + 1]--;
			s[r + 1] -= r - l - 1;
			s[r + 2] += r - l - 1;
		}
		else{
			r += m;
			s[l + 2]++;
			s[r + 1]--;
			s[r + 1] -= r - l - 1;
			s[r + 2] += r - l - 1;
		}
		
		tot += r - l;
	}
	
	for(i = 1; i < 2 * m; i++)
	s[i] = s[i - 1] + s[i];
	for(i = 1; i < 2 * m; i++)
	s[i] = s[i - 1] + s[i];
	
	long long res = 1e18;
	
	for(i = 0; i < m; i++)
	res = min(res, tmp - (s[i] + s[i + m]));
	
	printf("%lld\n", res);
}
