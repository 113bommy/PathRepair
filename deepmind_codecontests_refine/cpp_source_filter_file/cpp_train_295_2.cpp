#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	int a[3],ans[2];
	char com;
	ans[0]=0;ans[1]=0;
	while(cin>>a[0]>>com>>a[1]>>com>>a[2]){
		if(a[2]*a[2]==a[0]*a[0]+a[1]*a[1])ans[0]++;
		if(a[0]==a[1])ans[1]++;
	}
	cout<<ans[0]<<endl<<ans[1]<<endl;
	return 0;