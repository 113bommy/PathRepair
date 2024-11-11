#include<iostream>
using namespace std ;

int main(){
	int c,mn ;
	mx = 0 ;
	int ans = 0 ;
	for(int i=0;i<5;i++){
		cin >> c ;
		ans += (c+9)/10 ;
		if(mx<10-c%10&&c%10!=0) mn = 10-c%10 ;
	}
	cout << ans-mx << endl ;
}