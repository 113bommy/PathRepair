#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  for(int i=0;i<n;i++){
    cin >> p[i].second >> p[i].first;
  }
  sort(p.begin(),p.end());
  int t=0;
  string ans = "Yes";
  for(int i=0;i<n;i++){
    t += p[i].second;
    if(t > p[i].first){
      ans = "No";
      break;
    }
  }
  cout <<  ans  << endl;
}
