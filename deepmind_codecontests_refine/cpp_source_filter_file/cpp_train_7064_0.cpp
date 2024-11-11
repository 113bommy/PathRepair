#include<cstdio>
#include<iostream>
using namespace std;
int i;
char cf[3C]="CF",a[105];
int main(){
	scanf("%s",a);
	for(int j=0;a[j];j++){
		if(a[j]==cf[i])i++;
		if(i==2){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
