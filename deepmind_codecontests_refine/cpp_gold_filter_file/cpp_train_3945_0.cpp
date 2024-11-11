#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){

	while(1){
		int n=0,l,s;
		int cnt = 0;
		string tmp;

		cin >> tmp;
		n = atoi(tmp.c_str());

		if(n == 0)break;
		if(n % 1111 == 0){
			printf("NA\n");
			continue;
		}

		while(n != 6174){
			sort(tmp.begin(),tmp.end());
			s = atoi(tmp.c_str());

			sort(tmp.begin(),tmp.end(),greater<char>());
			l = atoi(tmp.c_str());
			n = l - s;

			for(int i=0,p=1000;i<4;i++,p/=10){
				tmp[i] = '0' + n/p;
				n %= p;
			}
			n = atoi(tmp.c_str());
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}