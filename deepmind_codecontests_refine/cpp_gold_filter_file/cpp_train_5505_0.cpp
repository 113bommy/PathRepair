#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	int seat[17] = {0};
	int X = 0;
	int stop[100] = {0};
	int time = 0;
	queue<int> Q;
	while(X < 100){
		int x;
		if(time%5 == 0 && time < 500){
			Q.push(time/5);
		}
		while(1){
			if(Q.size())x = Q.front();
			else x = -1;
			bool f = false;
			
			if(~x){
				int people = (x%5==1?5:2);
				int use = 19 + 3 * (x%3) + 17 * (x%2);
				rep(i,17-people+1){
					bool flag = true;
					rep(j,people){
						flag &= seat[i+j] == 0;
					}
					if(flag){
						rep(j,people){
							seat[i+j] = use;
						}
						f = true;
						break;
					}
				}
			}
			if(f){	
				stop[x] = time - x * 5;
				Q.pop();
				X++;
			}
			if(!f)break;
		}
		rep(i,17){
			seat[i] = max(0,seat[i]-1);
		}
		time++;
	}
	int n,c=0;
	
	while(cin >> n){
		if(n >= 50)c++;
		cout << stop[n] << endl;
	}
	while(c>=6){return 1;};
	
}