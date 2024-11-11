#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int id;
	double w, h;
	while (scanf("%d,%lf,%lf",&id,&w,&h) != EOF) {
		double bmi = w / (h*h);
		if (bmi >= 25.0) {
			cout << id << endl;
		}
	}
    return 0;
}