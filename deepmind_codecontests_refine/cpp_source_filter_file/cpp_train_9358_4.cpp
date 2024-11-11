#include <cstdio>
using namespace std;
int main()
{for(;;){
	int s,x;
	s=0;
	scanf("%d",&s);
	if(!s) return 0;
	for(int i=0;i<10;i++){{
		scanf("%d",&x);
		s-=x;
	}
	printf("%d\n",s);
	}
}