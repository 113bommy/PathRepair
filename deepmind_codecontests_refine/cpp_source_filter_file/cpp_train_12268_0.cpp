#include<iostream>
#include <map>

using namespace std;

int main(){
  int n;
  map<int,int>mp;
  cin >> n;
  while(n--){
    int i;
    cin >> i;
    mp[i]++;
  }
  cin >> n;
  while(n--){
    int i;
    cin >> i;
    if(mp[i]==0){
      cout << "NO" << endl;
      return 0;
    }
    mp[i]--;
  }
  cout << "YES" << endl;
}
}