#include <bits/stdc++.h> 
using namespace std;
unordered_set<int> m;
int main() {
  int n,k;
  cin >> n >> k;
  while(k--) {
	int d;
    cin >> d;
    while(d--) {
      int t;
      cin >> t;
      m.insert(t);
    }
  }
  cout << n - (int)m.size() << "\n";
  return 0;
}