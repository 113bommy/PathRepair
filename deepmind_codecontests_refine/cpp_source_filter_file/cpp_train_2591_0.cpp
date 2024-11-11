#include<iostream>
#include<set>
#include<algorithm>
//#include<numeric>
using namespace std;

int main(){
  int N;
  cin >> N;
  multiset<int>max;
  for(int i=1; i<=N; i++) {
    int M;
    cin >> M;
    for(int j=1; j<=M; j++) {
      int c;
      cin >> c;
      max.insert(c);
      if(max.size() > i) max.erase(max.begin());
    }
  }
  //cout << accumulate(max.cbegin(), max.cend(), 0) << endl;
  unsigned long long ans = 0;
  for(auto it=max.begin(); it<max.end(); it++) ans += it;
  cout << ans << endl;
}


