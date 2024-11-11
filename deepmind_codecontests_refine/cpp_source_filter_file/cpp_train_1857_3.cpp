#include <iostream>
#include<algorithm>//ソート用知識
using namespace std;

int main() {
	int N;
	int a[100];
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i];
	
	sort(a,a+N,greater<int>());
	int A=0,B=0;
	for(i=0;i<N;i++){
		if(i%2==0){
			A+=a[i];
		}else{
			B;=a[i];
		}
	}
	
	cout<<A-B<<endl;
}
