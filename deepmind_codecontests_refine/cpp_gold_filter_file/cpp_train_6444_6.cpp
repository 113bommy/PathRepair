#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	int A, B, C, D, E, F;
	scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);
	printf("%d\n", A + B + C + D + E + F - min(min(A, B), min(C, D)) - min(E, F));
	return 0;
}