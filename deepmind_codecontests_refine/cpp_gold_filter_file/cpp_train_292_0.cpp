#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int n,c=0;
	cin>>n;
	int p[100000];
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n;i++){
		if(p[i]==i+1){
			swap(p[i],p[i+1]);
			c++;
		}
	}
	cout<<c<<endl;
    return 0;
}