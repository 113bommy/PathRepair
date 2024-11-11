#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
static const double EPS = 1e-5;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <typename T, typename U>
T lexical_cast(const U& src) {
  T tmp;
  stringstream ss;
  ss << src;
  ss >> tmp;
  return tmp;
}
bool solve(map<int, int>::iterator fb, map<int, int>::iterator b,
           map<int, int>::iterator e, vector<int>::iterator oto,
           vector<int>::iterator tb, vector<int>::iterator te,
           map<int, vector<int> >& dst) {
  if (tb == te) return true;
  if (*tb == 0) {
    ++tb;
    return solve(fb, fb, e, oto, tb, te, dst);
  }
  if (b == e) return false;
  if (b->first > *tb) return false;
  for (int i = b->second; i >= 0; i--) {
    map<int, int>::iterator next = b;
    next++;
    *tb -= b->first * i;
    b->second -= i;
    if (solve(fb, next, e, oto, tb, te, dst)) {
      for (int j = 0; j < i; j++) {
        dst[int(tb - oto)].push_back(b->first);
      }
      return true;
    }
    b->second += i;
    *tb += b->first * i;
  }
  return false;
}
int main() {
  map<string, int> data;
  map<int, string> invdata;
  data["H"] = 1;
  data["He"] = 2;
  data["Li"] = 3;
  data["Be"] = 4;
  data["B"] = 5;
  data["C"] = 6;
  data["N"] = 7;
  data["O"] = 8;
  data["F"] = 9;
  data["Ne"] = 10;
  data["Na"] = 11;
  data["Mg"] = 12;
  data["Al"] = 13;
  data["Si"] = 14;
  data["P"] = 15;
  data["S"] = 16;
  data["Cl"] = 17;
  data["Ar"] = 18;
  data["K"] = 19;
  data["Ca"] = 20;
  data["Sc"] = 21;
  data["Ti"] = 22;
  data["V"] = 23;
  data["Cr"] = 24;
  data["Mn"] = 25;
  data["Fe"] = 26;
  data["Co"] = 27;
  data["Ni"] = 28;
  data["Cu"] = 29;
  data["Zn"] = 30;
  data["Ga"] = 31;
  data["Ge"] = 32;
  data["As"] = 33;
  data["Se"] = 34;
  data["Br"] = 35;
  data["Kr"] = 36;
  data["Rb"] = 37;
  data["Sr"] = 38;
  data["Y"] = 39;
  data["Zr"] = 40;
  data["Nb"] = 41;
  data["Mo"] = 42;
  data["Tc"] = 43;
  data["Ru"] = 44;
  data["Rh"] = 45;
  data["Pd"] = 46;
  data["Ag"] = 47;
  data["Cd"] = 48;
  data["In"] = 49;
  data["Sn"] = 50;
  data["Sb"] = 51;
  data["Te"] = 52;
  data["I"] = 53;
  data["Xe"] = 54;
  data["Cs"] = 55;
  data["Ba"] = 56;
  data["La"] = 57;
  data["Ce"] = 58;
  data["Pr"] = 59;
  data["Nd"] = 60;
  data["Pm"] = 61;
  data["Sm"] = 62;
  data["Eu"] = 63;
  data["Gd"] = 64;
  data["Tb"] = 65;
  data["Dy"] = 66;
  data["Ho"] = 67;
  data["Er"] = 68;
  data["Tm"] = 69;
  data["Yb"] = 70;
  data["Lu"] = 71;
  data["Hf"] = 72;
  data["Ta"] = 73;
  data["W"] = 74;
  data["Re"] = 75;
  data["Os"] = 76;
  data["Ir"] = 77;
  data["Pt"] = 78;
  data["Au"] = 79;
  data["Hg"] = 80;
  data["Tl"] = 81;
  data["Pb"] = 82;
  data["Bi"] = 83;
  data["Po"] = 84;
  data["At"] = 85;
  data["Rn"] = 86;
  data["Fr"] = 87;
  data["Ra"] = 88;
  data["Ac"] = 89;
  data["Th"] = 90;
  data["Pa"] = 91;
  data["U"] = 92;
  data["Np"] = 93;
  data["Pu"] = 94;
  data["Am"] = 95;
  data["Cm"] = 96;
  data["Bk"] = 97;
  data["Cf"] = 98;
  data["Es"] = 99;
  data["Fm"] = 100;
  invdata[1] = "H";
  invdata[2] = "He";
  invdata[3] = "Li";
  invdata[4] = "Be";
  invdata[5] = "B";
  invdata[6] = "C";
  invdata[7] = "N";
  invdata[8] = "O";
  invdata[9] = "F";
  invdata[10] = "Ne";
  invdata[11] = "Na";
  invdata[12] = "Mg";
  invdata[13] = "Al";
  invdata[14] = "Si";
  invdata[15] = "P";
  invdata[16] = "S";
  invdata[17] = "Cl";
  invdata[18] = "Ar";
  invdata[19] = "K";
  invdata[20] = "Ca";
  invdata[21] = "Sc";
  invdata[22] = "Ti";
  invdata[23] = "V";
  invdata[24] = "Cr";
  invdata[25] = "Mn";
  invdata[26] = "Fe";
  invdata[27] = "Co";
  invdata[28] = "Ni";
  invdata[29] = "Cu";
  invdata[30] = "Zn";
  invdata[31] = "Ga";
  invdata[32] = "Ge";
  invdata[33] = "As";
  invdata[34] = "Se";
  invdata[35] = "Br";
  invdata[36] = "Kr";
  invdata[37] = "Rb";
  invdata[38] = "Sr";
  invdata[39] = "Y";
  invdata[40] = "Zr";
  invdata[41] = "Nb";
  invdata[42] = "Mo";
  invdata[43] = "Tc";
  invdata[44] = "Ru";
  invdata[45] = "Rh";
  invdata[46] = "Pd";
  invdata[47] = "Ag";
  invdata[48] = "Cd";
  invdata[49] = "In";
  invdata[50] = "Sn";
  invdata[51] = "Sb";
  invdata[52] = "Te";
  invdata[53] = "I";
  invdata[54] = "Xe";
  invdata[55] = "Cs";
  invdata[56] = "Ba";
  invdata[57] = "La";
  invdata[58] = "Ce";
  invdata[59] = "Pr";
  invdata[60] = "Nd";
  invdata[61] = "Pm";
  invdata[62] = "Sm";
  invdata[63] = "Eu";
  invdata[64] = "Gd";
  invdata[65] = "Tb";
  invdata[66] = "Dy";
  invdata[67] = "Ho";
  invdata[68] = "Er";
  invdata[69] = "Tm";
  invdata[70] = "Yb";
  invdata[71] = "Lu";
  invdata[72] = "Hf";
  invdata[73] = "Ta";
  invdata[74] = "W";
  invdata[75] = "Re";
  invdata[76] = "Os";
  invdata[77] = "Ir";
  invdata[78] = "Pt";
  invdata[79] = "Au";
  invdata[80] = "Hg";
  invdata[81] = "Tl";
  invdata[82] = "Pb";
  invdata[83] = "Bi";
  invdata[84] = "Po";
  invdata[85] = "At";
  invdata[86] = "Rn";
  invdata[87] = "Fr";
  invdata[88] = "Ra";
  invdata[89] = "Ac";
  invdata[90] = "Th";
  invdata[91] = "Pa";
  invdata[92] = "U";
  invdata[93] = "Np";
  invdata[94] = "Pu";
  invdata[95] = "Am";
  invdata[96] = "Cm";
  invdata[97] = "Bk";
  invdata[98] = "Cf";
  invdata[99] = "Es";
  invdata[100] = "Fm";
  int n, m;
  cin >> n >> m;
  map<int, int> in;
  vector<int> out;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    in[data[str]]++;
  }
  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    out.push_back(data[str]);
  }
  vector<int> backup = out;
  map<int, vector<int> > dst;
  if (solve(in.begin(), in.begin(), in.end(), out.begin(), out.begin(),
            out.end(), dst)) {
    cout << "YES" << endl;
    int cnt = 0;
    for (map<int, vector<int> >::iterator iter = dst.begin(); iter != dst.end();
         iter++) {
      for (int i = 0; i < iter->second.size(); i++) {
        cout << invdata[iter->second[i]];
        if (i == iter->second.size() - 1) {
          cout << "->" << invdata[backup[cnt]] << endl;
        } else {
          cout << "+";
        }
      }
      cnt++;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
