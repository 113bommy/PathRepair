#include <stdio.h>
int main(){
	char a;
	scanf("%c",&a);
	if(a=='A')printf('T');
	else if(a=='T')printf('A');
	else if(a=='G')printf('C');
	else printf('G');
	printf("\n");
	return 0;
}
