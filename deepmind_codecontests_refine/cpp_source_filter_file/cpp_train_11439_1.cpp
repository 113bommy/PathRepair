//#define scanf_s scanf
//#define sscanf_s sscanf
//#define gets_s gets
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 11
#define HO 6
int main(void)
{
	int n;
	while (1) {
		scanf_s("%d", &n);
		if (n == 0) break;
		int date[MAX][MAX] = { 0 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf_s("%d", &date[i][j]);
				date[i][n] += date[i][j];
				date[n][j] += date[i][j];
				date[n][n] += date[i][j];
			}
		}
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				printf("%5d", date[i][j]);
			}
			printf("\n");
		}
		
	}
}