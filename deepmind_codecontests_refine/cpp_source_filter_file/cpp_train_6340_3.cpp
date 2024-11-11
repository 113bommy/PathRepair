#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int *a, *b, s, t, c;
	int p, q;
	a = &p;
	b = &q;
	while(cin >> p >> q){
		s = *a;
		t = *b;
		c = 1;
		for(int tmp = (*a > *b)? *b : *a, i = 2; i <= tmp; i++){
			while(s%i == 0 && t%i == 0){
				s /= i;
				t /= i;
				tmp /= i;
				c *= i;
			}
		}
		cout << c << " " << endl;
	return 0;
}