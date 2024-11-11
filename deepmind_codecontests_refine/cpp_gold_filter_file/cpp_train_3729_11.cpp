#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N , M;
	cin >> N >> M;
	vector<P> PY(M),py(M);
	for(int i=0;i<M;i++){
		cin >> PY[i].first >> PY[i].second;
		py[i] = PY[i];
	}
	sort(py.begin(),py.end());
	map<P , int> ans;
	int pre = py[0].first;
	int index = 0;
	for(int i=0;i<M;i++){
		if(pre == py[i].first){
			index++;
			ans[py[i]] = index;
		}else{
			index = 1;
			pre = py[i].first;
			ans[py[i]] = index;
		}
	}
	for(int i=0;i<M;i++)printf("%06d%06d\n",PY[i].first , ans[PY[i]]);
	return 0;
}
