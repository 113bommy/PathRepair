#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll aI, aO, aT, aJ, aL, aS, aZ;
	cin >> aI >> aO >> aT >> aJ >> aL >> aS >> aZ;
	if(aI%2 == aJ%2 && aJ%2 == aL%2){ cout << aI + aJ + aL + aO << endl; }
	else{
		if((aI + aJ + aL) % 2 == 0 && min(min(aI, aJ), aL) == 0){
			cout << aI + aJ + aL + aO - 2 << endl;
		}else{ cout << max(0LL, aI + aJ + aL + aO - 1) << endl; }
	}
	return 0;
}