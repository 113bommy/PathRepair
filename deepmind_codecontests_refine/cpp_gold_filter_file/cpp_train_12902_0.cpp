#include <iostream>
#include <bitset>
using namespace std;

int main() {
	bitset<8368800> flgs;

	while(1){
		flgs.reset();
		int m,n;
		// ?????????????????£????????°
		int loop = 0;
		cin >> m >> n;
		if(m == 0 && n == 0) break;

		if(m > n){
				cout << m + n << "\n";
		}else{
			int i;
	  	for(i = m ; loop <= n ; i++){
				if(flgs.test(i)){
				}else{
					loop++;
					int lim = 7368792 / i + 1;
					for(int j = 1 ; j < lim ; j++){
						flgs.set(i * j);
					}
		//			cout << "i = " << i << " loop = " << loop << "\n";
				}
			}

			cout << i - 1 << "\n";
		}
	}
	return 0;
}