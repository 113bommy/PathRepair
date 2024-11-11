#include <iostream>
#include <string>
using namespace std;
int GetMaxs(int date[], int n){
	int max=0, maxn=0;
	for(int i=0; i<n; i++){
		if(max<date[i]){
			max = date[i];
			maxn = i;
		}
	}
	return (maxn);
}

int main(void){
	int m[5],am,pm;
	string s;
	while(cin>>am>>pm,am){
		m[0] = am + pm;
		for(int i=1; i<5; i++){
			cin>>am>>pm;
			m[i] = am + pm;
		}
		s = 'A' + GetMaxs(m,5);
		cout << s << " " << m[GetMaxs(m,5)] <<endl;
	}
	return 0;
}