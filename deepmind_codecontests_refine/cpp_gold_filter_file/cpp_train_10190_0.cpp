#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class sorting{
public:
  bool operator()(const pair<int,int>& left,const pair<int,int>& right)const{
    return left.first < right.first;
  }
};

int main(){
  int n;
  while(cin >> n,n){
    vector<pair<int,int> > dat;
    int m,s,id;
    for(int i=0;i<n;i++){
      int total = 0;
      cin >> id;
      for(int j=0;j<4;j++){
	cin >> m >> s;
	total += m*60 + s;
      }
      dat.push_back(make_pair(total,id));
    }
    sort(dat.begin(),dat.end(),sorting());
    cout << dat[0].second << endl << dat[1].second << endl << dat[n-2].second << endl;
  }
}