#include<stdio.h>

int main()
{
	int n=0, s[5];
	char s[5];
	scanf("%s", s);
	for (i = 0; i < 5; i++){
		if (s[i] == '+'){
			n++;
		}
		else{
			n--;
		}
	}
	printf("%d", n);
	return 0;
}