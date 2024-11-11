#include <iostream>
using namespace std;
int main(void){
	int i, n, b, f;
	char a[1010];
	for(cin >> n; n; n--, , b = 0, f = 0){
		for(cin >> a, i = 0; a[i] != '\0'; i++){
			b += (int)(a[i] - '0');
			if(b > 9) b = b - 9;
			else f = !f;
		}
		if(f) cout << "Audrey wins."<< endl;
		else cout << "Fabre wins." << endl;
	}
	return 0;
}