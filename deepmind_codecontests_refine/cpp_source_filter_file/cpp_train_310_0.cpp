#include<iostream>

int main(){
	int n;
	std::cin >> n;
	int ans=0;
	for (int i = 0; i < n; ++i){
		int a;
		std::cin >> a;
		bool f = true;
		for (int j = 2; j*j < a; ++j){
			if (a%j == 0)f = false;
		}
		if (f)ans++;
	}
	std::cout << ans < std::endl;
	return 0;
}