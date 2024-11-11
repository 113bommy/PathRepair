#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[4];
	rep(i,4) scanf("%d",&a[i]);
	sort(a,a+4)
	puts(a[0]==1&&a[1]==9&&a[2]==7&&a[3]==4?"YES":"NO");
	return 0;
}
