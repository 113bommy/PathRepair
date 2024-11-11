include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	char a[101];
	int s,cn=0,i,f;
	while (cin >> a) {
     s=strlen(a); f=0;
     for (i=0;i<(s+1)/2;i++) if (a[i]!=a[s-1-i]) f=1;
	 if (f==0) cn++;
	}
	cout << cn << endl;
	return 0;
}