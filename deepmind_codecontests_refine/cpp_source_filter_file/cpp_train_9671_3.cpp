#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

typedef pair<int,int> P;

int bit[100001][2],n;
vector<P> bug;

int sum(int i,int num){
	int s = 0;
	while(i > 0){
		s += bit[i][num];
		i -= i & -i;
	}
	return s;
}

void add(int i,int x,int num){
	while(i <= 100000){
		bit[i][num] += x;
		i += i & -i;
	}
}

bool C(int x,int ok){
	return sum(x,0) * ok >= sum(x,1);
}

int main(){
	int ma = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b;
		bug.push_back(P(b,a));
	}
	sort(bug.begin(),bug.end(),greater<P>());
	for(int i = 0;i < n;i++){
		int ok = bug[i].first,foo = bug[i].second;
		add(foo,1,0);
		add(foo,foo,1);
		int low = 0,up = 100001;
		while(up - low > 1){
			int mid = (up + low) / 2;
			if(C(mid,ok)) low = mid;
			else up = mid;
		}
		int s = sum(low,0);
		if(low != 100000 && sum(low + 1,0) - sum(low,0) >= 2){
			int j = 1;
			for(;j < sum(low + 1,0) - sum(low,0);j++){
				if((sum(low,0) + j) * ok < sum(low,1) + j * (low + 1)) break;
			}
			s += j - 1;
		}
		ma = max(s,ma);
	}
	cout << ma << endl;
	return 0;
}