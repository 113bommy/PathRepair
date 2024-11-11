#include<cstdio>
using namespace std;
inline int f(int n, int s, int t)
{
	if(!t)return n/s;
	return f(n-((n/s-t+s)/s)*s,s,(t+((n/s-t+s)/s)*(s-1))%(n/s-((n/s-t+s)/s)+1));
}
int main()
{
	int T, x=0, n, s;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &s);
		x^=f(n-n%s, s, n%s);
	}
	printf(x?"Takahashi\n":"Aoki\n");
	return 0;
}