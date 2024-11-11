#include <stdio.h>

int main(void) {

	int a, i;
	int ans=0;


	for (i = 0; i < 10; i++) {

		scanf_s("%d", &a);

		ans = ans + a;

	}
	printf("%d\n", ans);
	

	return 0;
}
