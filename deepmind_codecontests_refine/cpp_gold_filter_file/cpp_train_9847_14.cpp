#include <bits/stdc++.h>
using namespace std;
struct node {
  string name;
  string real_value;
  string oper;
  string var1;
  int var1_index;
  string var2;
  int var2_index;
};
int n, m;
node f[5001];
map<string, int> NameToIndex;
void init_data() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string var_name, sign, var_name1, oper, var_name2;
    cin >> var_name >> sign >> var_name1;
    f[i].name = var_name;
    if (var_name1[0] == '0' || var_name1[0] == '1') {
      f[i].real_value = var_name1;
    } else {
      cin >> oper >> var_name2;
      f[i].oper = oper;
      f[i].var1 = var_name1;
      f[i].var2 = var_name2;
    }
  }
}
void tr_string_to_index() {
  NameToIndex["?"] = n;
  for (int i = 0; i < n; i++) NameToIndex[f[i].name] = i;
  for (int i = 0; i < n; i++) {
    f[i].var1_index = NameToIndex[f[i].var1];
    f[i].var2_index = NameToIndex[f[i].var2];
  }
}
vector<int> vecNode;
vector<int> vecDig[5001];
int dig_node[5001];
void cal_dig_node() {
  vecNode.push_back(n);
  dig_node[n] = 0;
  for (int i = 0; i < n; i++) {
    vecNode.push_back(i);
    if (!f[i].oper.size()) {
      dig_node[i] = 0;
    } else {
      if (f[i].var1 == "?" && f[i].var2 == "?") {
        dig_node[i] = 1;
        vecDig[n].push_back(i);
      } else {
        dig_node[i] = 2;
        vecDig[f[i].var1_index].push_back(i);
        vecDig[f[i].var2_index].push_back(i);
      }
    }
  }
}
vector<int> tpDig;
void get_tp_dig() {
  size_t iPos = 0;
  while (tpDig.size() < n + 1) {
    for (size_t i = 0; i <= n; i++) {
      if (dig_node[i] == 0) {
        tpDig.push_back(i);
        dig_node[i] = -1;
      }
    }
    for (; iPos != tpDig.size(); iPos++) {
      for (size_t i = 0; i < vecDig[tpDig[iPos]].size(); i++)
        dig_node[vecDig[tpDig[iPos]][i]]--;
    }
  }
}
int value[5001] = {0};
int sum_of_one(int pos, int bit) {
  int sum = 0;
  value[n] = bit;
  for (int i = 0; i < tpDig.size(); i++) {
    if (tpDig[i] == n) continue;
    int x = tpDig[i];
    if (f[x].oper == "OR")
      value[x] = value[f[x].var1_index] | value[f[x].var2_index];
    else if (f[x].oper == "AND")
      value[x] = value[f[x].var1_index] & value[f[x].var2_index];
    else if (f[x].oper == "XOR")
      value[x] = value[f[x].var1_index] ^ value[f[x].var2_index];
    else
      value[x] = f[x].real_value[pos] == '0' ? 0 : 1;
    sum += value[x];
  }
  return sum;
}
void gao() {
  char min_bit[1001] = {0};
  char max_bit[1001] = {0};
  for (int i = 0; i < m; i++) {
    int sum_bit_zero = sum_of_one(i, 0);
    int sum_bit_one = sum_of_one(i, 1);
    min_bit[i] = '0';
    max_bit[i] = '0';
    if (sum_bit_zero > sum_bit_one) min_bit[i] = '1';
    if (sum_bit_zero < sum_bit_one) max_bit[i] = '1';
  }
  cout << min_bit << endl;
  cout << max_bit << endl;
}
int main(int argc, char* argv[]) {
  init_data();
  tr_string_to_index();
  cal_dig_node();
  get_tp_dig();
  gao();
  return 0;
}
