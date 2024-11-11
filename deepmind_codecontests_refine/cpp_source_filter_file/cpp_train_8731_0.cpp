#include <iostream>
using namespace std;
int s[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 4, 3, 2, 1};

void disp(int a, int b){
	for(int i = a+1;;i++){
		cout << " " << s[i%15];
		if(s[i%15] == b){cout << endl;return 0;}
	}
}

int main(){
	int n, a, b;cin >> n;
	while(n--){
		cin >> a >> b;cout << a;
		if(6 <= a && a <= 9)disp(a, b);
		else disp(0 < b-a ? a : 15-a, b);
	}
	return 0;
}