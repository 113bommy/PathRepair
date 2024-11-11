#include <stdio.h>

int main(void)
{
    int a, b, year, answer, i;
    i = 0;
    while(1) {
	scanf("%d %d", &a, &b);
	if (a == 0 && b == 0) {
	    break;
	}
	if (i !=0) {
	    pritnf("\n");
	i++;
	answer = 0;
	for (year = a; year <= b; year++) {
	    if (year % 4 == 0) {
		if (year % 100 != 0) {
		    printf("%d\n", year);
		    answer++;
		} else if (year % 400 == 0) {
		    printf("%d\n", year);
		    answer++;
		}
	    }
	}
	if (answer == 0) {
   	    printf("NA\n");
	}
    }
    return 0;
}