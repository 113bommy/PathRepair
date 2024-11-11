#iclude <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,k; scanf("%d%d%d%d",&a,&b,&c,&k);
	int ans = min(a,k);
	if (a+b<k) {
		ans-=min(c-a-b,c);
	}
	printf("%d",ans);
}