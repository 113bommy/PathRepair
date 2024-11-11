#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	long float x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << fixed << sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) << endl;
    return 0;
}