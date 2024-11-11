#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int id;
	double w, h;
	while (scanf_s("%d,%lf,%lf",&id,&w,&h)) {
		double bmi = w / (h*h);
		if (bmi >= 25.0) {
			cout << id << endl;
		}
	}
    return 0;
}