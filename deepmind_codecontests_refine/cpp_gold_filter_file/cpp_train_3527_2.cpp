#include<iostream>
using namespace std;

int q1,q2,b,c1,c2,ans1,ans2;

bool solve(){
	if(!q2)
		return false;
	ans1 = q2;
	ans2 = 0;
	while(ans1*c1 + ans2*c2 <= b)
		ans2++;
	if(ans2)
		ans2--;
	if(ans1 + ans2 >= q1 && ans1*c1 + ans2*c2 <= b)
		return true;
	while(true){
		ans1--;
//		if(!ans1)
//			return false;
		while(true){
			ans2++;
			if(ans1*c1 + ans2*c2 > b){
				ans2--;
				break;
			}
		}
		if((ans1*c1 + ans2*c2 <= b && ans1 + ans2 >= q1) || ans1 == 0)
			break;
	}
	if(!ans1)
		return false;
	else
		return true;
}

int main(){
	while(true){
		cin >> q1;
		if(!q1)
			return 0;
		cin >> b >> c1 >> c2 >> q2;
		if(solve())
			cout << ans1 << ' ' << ans2 << endl;
		else
			cout << "NA" << endl;
	}
}