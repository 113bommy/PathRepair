#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	char abacus[8][10] = {
		"*****     ",
		"     *****",
		"==========",
		" **** ****",
		"* **** ***",
		"** **** **",
		"*** **** *",
		"**** **** ",
	};
	
	int n;
	bool flag = false;
	while (scanf("%d", &n) != EOF){
		int num[5];
		char a[8][5];
		for (int i = 0; i < 5; i++){
			num[4 - i] = n % 10;
			n /= 10;
		}
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 5; j++){
				a[i][j] = abacus[i][num[j]];
			}
		}
		
		if (flag){
			cout << endl;
		}
		
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 5; j++){
				cout << a[i][j];
			}
			cout << endl;
		}
		flag = true;
	}
	
	return (0);
}