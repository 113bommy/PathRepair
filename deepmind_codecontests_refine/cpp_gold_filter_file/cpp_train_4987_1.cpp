#include<iostream>
#include<string>
using namespace std;

int main(){
	string a,b;
	int n,m;
	int i,j,k,l;
	int s=0,e=0;
	cin>>n>>a;
	for(i=0;i<n;i++){
		cin>>b;
		for(j=0;j<b.size();j++){
			for(k=0;k<b.size();k++){
				e=0;
				for(l=0;l<a.size();l++){
					if(j+k*l>=b.size() || b[j+k*l]!=a[l]){
						e=1;
						break;
					}
				}
				if(e==0){
					e=2; s++;
					break;
				}
			}
			if(e==2){
				e=0; break;
			}
		}
	}
	cout<<s<<endl;
	return 0;			
}