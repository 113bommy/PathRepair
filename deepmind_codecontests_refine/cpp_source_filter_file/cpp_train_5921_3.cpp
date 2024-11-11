#include <iostream>
#include<cstdio>
using namespace std;
int main (){
	int w,N,d[30],sub;
	int a,b;

	cin>>w>>N;
	for(int j=1;j<=w;j++){
		d[j]=j;
	}
	for(int i=0;i<N;i++){
        scanf("%d,%d",&a,&b);
		sub=d[b];
		d[b]=c[a];
		c[a]=sub;
	}
	for(int k=1;k<=w;k++){
	cout<<d[k]<<endl;
	}

	return 0;
}