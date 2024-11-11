#include<cstdio>
#include<algorithm>
using namespace std;

int l, r;

int main() {
	scanf("%d%d", &l, &r);
	
	if(r-l>=2019) puts("0");
	else {
		int ans = 2018;
		for(int i=l;i<=r;i++)
			for(int j=i+1;j<=r;j++)
				ans = min(ans, int(1LL*i*j%2019));
		printf("%d\n", ans);
	}
	
	return 0;
}