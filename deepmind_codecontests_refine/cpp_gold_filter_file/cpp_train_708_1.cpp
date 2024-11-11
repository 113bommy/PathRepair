#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B;
  	string S;
  	cin >> A >> B >> S;
  	if(S.find("-")== A and S.find("-", A+1)==string::npos) {
    	cout << "Yes" << endl;
    }else{
    	cout << "No" << endl;
    }
}