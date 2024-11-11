#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;
	int sumLoad[100001];
	int now;
	int ans;
	
	scanf("%d%d", &n, &m);
	
	sumLoad[0] = 0;
	for (int i = 0; i < n - 1; i++){
		scanf("%d", &sumLoad[i + 1]);
		sumLoad[i + 1] += sumLoad[i];
	}
	
	now = 0;
	ans = 0;
	for (int i = 0; i < m; i++){
		int a;
		scanf("%d", &a);
		
		ans = (ans + abs(sumLoad[now + a] - sumLoad)) % 100000;
		now += a;
	}
	
	printf("%d\n", ans);
	
	return (0);
}