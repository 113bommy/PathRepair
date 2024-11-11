#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  long long n,ans=0;
  cin >> n;
  map<string int> m;
  string s;
  for(int i=0; i<n; i++) {
    cin >> s;
    sort(s.begin(),s.end());
    ans+=m[s];
    m[s]++;
  }
  cout << ans << endl;
}