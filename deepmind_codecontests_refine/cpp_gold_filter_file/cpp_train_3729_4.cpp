#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> p(m);
  vector<int> y(m);
  vector<int> py[100001];
  for(int i=0;i<m;i++){
    cin>>p[i]>>y[i];
    py[p[i]].push_back(y[i]);
  }
  for(int i=0;i<n;i++){
    sort(py[i+1].begin(),py[i+1].end());
  }
  for(int i=0;i<m;i++){
    printf("%06d%06d\n",p[i],(lower_bound(py[p[i]].begin(),py[p[i]].end(),y[i]))-py[p[i]].begin()+1);
  }
  return 0;
}
