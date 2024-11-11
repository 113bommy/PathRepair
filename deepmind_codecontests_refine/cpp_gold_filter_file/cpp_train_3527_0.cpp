#include <iostream>

using namespace std;

int main() {
	int q1, b, c1, c2, q2;
	while(cin >> q1, q1) {
	   cin >> b >> c1 >> c2 >> q2;
	   int aizu = min(b / c1, q2);
	   if (aizu == 0) {
		   cout << "NA" << endl;
		   continue;
	   }
	   int money = b - aizu * c1;
	   int ordinal = money / c2;

	   bool possible = true;
	   while (aizu + ordinal < q1) {
		   aizu--;
		   if (aizu == 0) {
			   cout << "NA" << endl;
			   possible = false;
			   break;
		   }
		   money = b - aizu * c1;
		   ordinal = money / c2;
		   money = b - aizu * c1 - ordinal * c2;
	   }
	   if (possible) cout << aizu << ' ' << ordinal << endl;
	}
	return 0;
}