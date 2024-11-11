#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  map<string, string> map1;
  map<string, string>::iterator it;
  map<string, map<string, string>::iterator> map2;
  map<string, map<string, string>::iterator>::iterator it2;
  string a, b;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    it2 = map2.find(a);
    if (it2 != map2.end() && it2->second != map1.end()) {
      it2->second->second = b;
      map2[b] = it2->second;
      it2->second = map1.end();
    } else {
      map1[a] = b;
      map2[b] = map1.find(a);
    }
  }
  cout << map1.size() << endl;
  for (it = map1.begin(); it != map1.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
}
