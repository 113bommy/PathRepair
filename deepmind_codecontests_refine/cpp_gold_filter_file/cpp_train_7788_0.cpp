#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
const int M=100010;

int main(){
	int even[M]={},odd[M]={};
	int n; 
	
	cin >>n;
	for(int i=0;i<n;i++){
		int v;
		cin >>v;
		if(i%2==0)
			even[v]++;
		else
			odd[v]++;
	}
	int max1=0;
	int max2=0;
	for(int i=0;i<M;i++)
		if(even[max1]<even[i])
			max1=i;
	for(int i=0;i<M;i++)
		if(odd[max2]<odd[i]&&max1!=i)
			max2=i;
	int cnt1=even[max1]+odd[max2];

	max1=0;max2=0;
	for(int i=0;i<M;i++)
		if(odd[max1]<odd[i])
			max1=i;
	for(int i=0;i<M;i++)
		if(even[max2]<even[i]&&max1!=i)
			max2 =i;
	int cnt2=odd[max1]+even[max2];
	cout << min(n-cnt1,n-cnt2)<< endl;
}