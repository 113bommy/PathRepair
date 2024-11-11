#include <bits/stdc++.h>
using namespace std;
struct Uczestnik {
  string imie;
  int pkt;
  Uczestnik(string imie, int pkt) : imie(imie), pkt(pkt) {}
};
bool cmp(const Uczestnik a, const Uczestnik b) { return a.pkt < b.pkt; }
class topka {
 public:
  vector<Uczestnik> uczestnicy;
  topka() {
    for (int i = 0; i < 3; ++i) {
      uczestnicy.push_back(Uczestnik("zzz", -1));
      ;
    }
  }
  int findMin() {
    int min;
    if (uczestnicy[0].pkt < uczestnicy[1].pkt)
      min = 0;
    else
      min = 1;
    if (uczestnicy[2].pkt < uczestnicy[min].pkt) min = 2;
    return min;
  }
  void zastap(Uczestnik uczestnik, int l) { uczestnicy[l] = uczestnik; }
};
int main() {
  int n, regions;
  cin >> n >> regions;
  vector<topka> liderzy(regions);
  for (int i = 0; i < n; ++i) {
    string imie;
    int region, pkt;
    cin >> imie;
    cin >> region >> pkt;
    --region;
    int min = liderzy[region].findMin();
    if (liderzy[region].uczestnicy[min].pkt < pkt)
      liderzy[region].zastap(Uczestnik(imie, pkt), min);
  }
  for (int i = 0; i < regions; ++i)
    sort(liderzy[i].uczestnicy.begin(), liderzy[i].uczestnicy.end(), cmp);
  for (int i = 0; i < regions; ++i) {
    if (liderzy[i].uczestnicy[0].pkt < liderzy[i].uczestnicy[1].pkt) {
      cout << liderzy[i].uczestnicy[2].imie << " "
           << liderzy[i].uczestnicy[1].imie << endl;
    } else
      cout << "?" << endl;
  }
}
