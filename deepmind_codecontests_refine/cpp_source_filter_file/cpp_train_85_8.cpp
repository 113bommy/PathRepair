#include<iostream>
#include<cmath>
#define MAX 1000000007
using namespace std;
int a[55][2];
int b[55][2];

int main(){
	int n,m;
	int i,j,k;
	int s[2];
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(i=0;i<m;i++){
		cin>>b[i][0]>>b[i][1];
	}
	for(i=0;i<n;i++){
		s[0]=MAX,s[1]=0;
		for(j=0;j<m;j++)a{
			k=abs(a[i][0]-b[j][0])+abs(a[i][1]-b[j][1]);
			if(k<s[0])s[0]=k,s[1]=j;
		}
		cout<<s[1]+1<<endl;
	}
	return 0;
}
