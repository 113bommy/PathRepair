#include <iostream>
#include <vector>
using namespace std;
#define MAXVALUE (1<<21)
vector<int> dp(5000+1,MAXVALUE);

void init(){
	int item[6] = {200,300,500,1000,1200,1500};
	int price[6]= {380,550,850,1520,1870,2244};
	
	dp[0]=0;

	for(int k=0;k<6;k++){
		for(int i=0;i+item[k]<=5000;i++){
			dp[i+item[k]] = min( dp[i+item[k]] , dp[i]+price[k] );
		}
	}
}

int main(){
	init();
	int n,mi;
	while(cin >> n && n){
		mi = dp[n];
		/*for(int i=n;i<=5000;i++){
			mi = min(dp[i],mi);
		}*/
		cout << mi << endl;
	}
}