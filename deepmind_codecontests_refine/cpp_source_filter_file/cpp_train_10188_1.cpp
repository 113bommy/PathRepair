#include <iostream>
using namespace std;

int n;
int p[20000];
int a[20000],b[20000];

void input(){
	int x;
	cin>>n;
	for(int i=0;i<na;i++){
		cin>>x;
		p[x-1]=i;
	}
}
void solve(){
	for(int i=0;i<n;i++){
		a[i]=(i+1)*30000;
		b[i]=999999999-(a[i]-p[i]);
	}
	
}

int main() {
	input();
	solve();
	for(int i=0;i<n-1;i++){
		cout<<a[i]<<" ";
	}
	cout<<a[n-1]<<endl;
	
	for(int i=0;i<n-1;i++){
		cout<<b[i]<<" ";
	}
	cout<<b[n-1]<<endl;
}