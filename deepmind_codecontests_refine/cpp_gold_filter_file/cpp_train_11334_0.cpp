#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> da[31];
int main() {
	int id,sc,n,i,j;
	while (scanf("%d,%d",&id,&sc)) {
		if (id==0 && sc==0) break;
		da[sc].push_back(id);
	}
	while (cin >> id) {
		n=0;  
		for (i=30;i>=0;i--) {
			if (da[i].size()>0) {
				n++;
				for (j=0; j<da[i].size(); j++) if (da[i][j]==id) cout << n << endl;
			}
		}
	}
	return 0;
}