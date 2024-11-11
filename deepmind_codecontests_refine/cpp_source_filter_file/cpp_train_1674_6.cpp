#include<iostream>
using namespace std;
int main(){
	int a=1,b=1;
	while(!(a==0&&b==0)){
		cin >> a >> b;
		for (int i=1;i<=a;i++){
			for(int j=1;j<=b;j++)
				if (i==1||i==x||j==1||j==y)
					cout << '#';
				else
					cout << '.';
			cout << endl;
		}
		if(!(a==0&&b==0))
			cout << endl;
	}
    return 0;
}
