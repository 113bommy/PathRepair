#include <bits/stdc++.h>
using namespace std;

typedef complex<int> P;

namespace std{
	bool operator < (const P &a,const P &b){
		if( a.real() != b.real() ) return a.real() < b.real();
		return a.imag() < b.imag();
	}
	bool operator == (const P &a,const P &b){
		if( a.real() != b.real() ) return false;
		return a.imag() == b.imag();
	}
};

vector<vector<P>> ptn = {
	{P(0,0),P(1,1),P(1,0),P(0,1)},
	{P(0,0),P(0,2),P(0,1),P(0,3)},
	{P(0,0),P(1,0),P(2,0),P(3,0)},
	{P(1,0),P(1,1),P(0,1),P(0,2)},
	{P(0,0),P(1,0),P(1,1),P(2,1)},
	{P(0,0),P(0,1),P(1,1),P(1,2)},
	{P(1,0),P(2,0),P(0,1),P(1,1)}
};

string s[8];
int main(){
	while(true){
		for(int i = 0 ; i < 8 ; i++){
			if(!(cin >> s[i]))exit(0);
			
		}
		for(int i = 0 ; i < 7 ; i++)
			sort(ptn[i].begin(),ptn[i].end());
		for(int i = -10 ; i <= 10 ; i++)
			for(int j = -10 ; j <= 10 ; j++){
				vector<P> tmp;
				for(int y = 0 ; y < 8 ; y++)
					for(int x = 0 ; x < 8 ; x++){
						if( s[y][x] == '1'){
							tmp.push_back(P(x-j,y-i));
						}
					}
				sort(tmp.begin(),tmp.end());
				for(int k = 0 ; k < 7 ; k++){
					if( tmp == ptn[k] ){
						cout << (char)(k+'A') << endl;
					}
				}
			}
	}
					
					
	
	
}