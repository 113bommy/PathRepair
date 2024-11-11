#include <stdio.h>
char a[300];
char b[300];
int ans;
int main(){
	scanf("%s",a);
	scnaf("%s",b);
	for(int i=0;i<3;i++){
		if(a[i]==b[i])ans++;
	}
	printf("%d\n",ans);
}