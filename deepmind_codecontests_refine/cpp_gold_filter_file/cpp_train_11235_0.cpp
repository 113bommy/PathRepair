#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printAns(int t1, int t2){
	int h1 = t1/3600, m1 = (t1%3600)/60, s1 = t1%60;
	int h2 = t2/3600, m2 = (t2%3600)/60, s2 = t2%60;
	printf("%02d:%02d:%02d %02d:%02d:%02d\n", h1, m1, s1, h2, m2, s2);
}

int main(){
	int n;
	while(cin >> n, n){
		vector< pair<int,int> > v;
		for(int i=0;i<n;i++){
			int t[3];
			cin >> t[0] >> t[1] >> t[2];
			sort(t, t+3);
			do{
				for(int j=0;j<60;j++){
					if(t[0]%5 == t[1]/12)
						v.push_back(make_pair((t[0]/5)*3600 + t[1]*60 + t[2],i));
					for(int k=0;k<3;k++) t[k] = (t[k]+1)%60;
				}
			}while(next_permutation(t,t+3));
		}
		sort(v.begin(), v.end());
		int start = 0, end = 12*60*60;
		for(int i=0;i<v.size();i++){
			int s = v[i].first, e = -1;
			bool see[10] = {}; see[v[i].second] = true;
			int count = 1;
			for(int j=i+1;j<v.size();j++){
				if(see[v[j].second]) continue;
				see[v[j].second] = true;
				count++;
				if(count == n) {
					e = v[j].first;
					break;
				}
			}
			if(e == -1) break;
			if(end-start > e-s) start = s, end = e;
		}
		printAns(start, end);
	}
}