#include<stdio.h>
#include<set>
using namespace std;
int n,x;
set<int> s;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		if(s.find(x)!=s.end()) s.erase(x);
		else s.insert(x);
	}
	printf("%d\n",s.size());
	return 0;
}