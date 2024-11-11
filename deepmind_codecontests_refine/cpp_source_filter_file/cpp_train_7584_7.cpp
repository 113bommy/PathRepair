#include<bits/stdc++.h>
using namespace std;

int main() {
vector<string> str(3);
for (int  i = 0; i < 3; i++) {
cin >> str[i];
}
vector<int> cnt(3,0);
int pass = 0;
while (1) {
for (int i = 0; i < 3; i++) {
if (cnt[i] == str[i].length()) {
cout << char('A' + i) << endl;
return 0;
}
}
cnt[pass]]++;
pass = str[pass][cnt[pass]] - 'a';
}
}