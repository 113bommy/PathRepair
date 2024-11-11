#include <bits/stdc++.h>
using namespace std;
int n, e;
bool type[100001];
string pos, ele;
string name[100001];
const string filler = "000000";
queue<string> qe, qr, qep, qrp, qbep, qbrp;
set<string> efinal, rfinal;
vector<string> script;
int main() {
  e = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> name[i] >> type[i];
    if (type[i] == 1) {
      e++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i <= e) {
      efinal.insert(to_string(i));
    } else {
      rfinal.insert(to_string(i));
    }
  }
  for (int i = 0; i < n; i++) {
    if (efinal.count(name[i])) {
      efinal.erase(name[i]);
      if (type[i] == 0) {
        qbrp.push(name[i]);
      }
    } else if (rfinal.count(name[i])) {
      rfinal.erase(name[i]);
      if (type[i] == 1) {
        qbep.push(name[i]);
      }
    } else if (type[i] == 1) {
      qe.push(name[i]);
    } else if (type[i] == 0) {
      qr.push(name[i]);
    }
  }
  for (auto ele : efinal) {
    qep.push(ele);
  }
  for (auto ele : rfinal) {
    qrp.push(ele);
  }
  while (qep.size() + qrp.size() + qbep.size() + qbrp.size() + qe.size() +
         qr.size()) {
    if (qbep.size() && qep.size()) {
      pos = qep.front();
      ele = qbep.front();
      qep.pop();
      qbep.pop();
      script.push_back("move " + ele + " " + pos);
      qrp.push(ele);
    } else if (qbrp.size() && qrp.size()) {
      pos = qrp.front();
      ele = qbrp.front();
      qrp.pop();
      qbrp.pop();
      script.push_back("move " + ele + " " + pos);
      qep.push(ele);
    } else if (qe.size() && qep.size()) {
      pos = qep.front();
      ele = qe.front();
      qep.pop();
      qe.pop();
      script.push_back("move " + ele + " " + pos);
    } else if (qr.size() && qrp.size()) {
      pos = qrp.front();
      ele = qr.front();
      qrp.pop();
      qr.pop();
      script.push_back("move " + ele + " " + pos);
    } else {
      ele = qbrp.front();
      qbrp.pop();
      script.push_back("move " + ele + " " + filler);
      qep.push(ele);
      qr.push(filler);
    }
  }
  cout << script.size() << endl;
  for (auto ele : script) {
    cout << ele << endl;
  }
  return 0;
}
