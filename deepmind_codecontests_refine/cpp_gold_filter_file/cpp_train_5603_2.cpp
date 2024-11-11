#include <iostream>
#include <map>
using namespace std;

int N;

int main(){
	cin >> N;
	map<int,int> m;
	for(int i=2;i<=N;i++){
		int s = i;
		for(int j=2;j*j<=N;j++){
			while(s%j==0){
				m[j]++;
				s /= j;
			}
		}
		if(s!=1) m[s]++;	
	}
	int ans = 0;
	int c2 = 0,c4 = 0,c14 = 0,c24 = 0,c74 = 0;
	for(auto x:m){
		int s = x.second;
		if(s>=2) c2++;
		if(s>=4) c4++;
		if(s>=24) c24++;
		if(s>=14) c14++;
		if(s>=74) c74++;
	}
	cout << (c2-2)*c4*(c4-1)/2 + (c2-1)*c24 + (c4-1)*c14 + c74 << endl;
}