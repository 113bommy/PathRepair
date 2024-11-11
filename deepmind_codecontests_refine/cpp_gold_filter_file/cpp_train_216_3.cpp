#include <bits/stdc++.h>
using namespace std;
struct item {
  string name;
  char type;
  int size;
  int param;
  bool operator<(const item &sec) const { return type < sec.type; }
} arr[1005];
int q1, q2, q3;
struct man {
  string name, home;
  int tough;
  bool operator<(const man &sec) const { return tough > sec.tough; }
};
man r1[1005];
man r2[1005];
man r3[1005];
void output(string name) {
  for (int i = 0; i < q1; i++) {
    if (r1[i].home == name) {
      cout << r1[i].name << " ";
    }
  }
  for (int i = 0; i < q2; i++) {
    if (r2[i].home == name) {
      cout << r2[i].name << " ";
    }
  }
  for (int i = 0; i < q3; i++) {
    if (r3[i].home == name) {
      cout << r3[i].name << " ";
    }
  }
}
int main() {
  int n, m, space = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    int a, d, o;
    cin >> arr[i].name >> s >> a >> d >> o >> arr[i].size;
    space += arr[i].size;
    if (s == "weapon") {
      arr[i].type = 0;
      arr[i].param = a;
    } else if (s == "armor") {
      arr[i].type = 1;
      arr[i].param = d;
    } else if (s == "orb") {
      arr[i].type = 2;
      arr[i].param = o;
    } else {
      throw "Wrong format Exception";
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    string name;
    string type;
    int tough;
    string home;
    cin >> name >> type >> tough >> home;
    if (type == "gladiator") {
      r1[q1].name = name;
      r1[q1].tough = tough;
      r1[q1].home = home;
      q1++;
    } else if (type == "sentry") {
      r2[q2].name = name;
      r2[q2].tough = tough;
      r2[q2].home = home;
      q2++;
    } else if (type == "physician") {
      r3[q3].name = name;
      r3[q3].tough = tough;
      r3[q3].home = home;
      q3++;
    } else {
      throw "Wrong format Exception";
    }
  }
  if (space == m) {
    for (int i = 0; i < q1; i++) {
      for (int j = 0; j < n; j++) {
        if (r1[i].home == arr[j].name && arr[j].type == 0) {
          arr[j].param += r1[i].tough;
        }
      }
    }
    for (int i = 0; i < q2; i++) {
      for (int j = 0; j < n; j++) {
        if (r2[i].home == arr[j].name && arr[j].type == 1) {
          arr[j].param += r2[i].tough;
        }
      }
    }
    for (int i = 0; i < q3; i++) {
      for (int j = 0; j < n; j++) {
        if (r3[i].home == arr[j].name && arr[j].type == 2) {
          arr[j].param += r3[i].tough;
        }
      }
    }
    int b1 = -1, b2 = -1, b3 = -1;
    for (int i = 0; i < n; i++) {
      if (arr[i].type == 0) {
        if (b1 == -1 || arr[b1].param < arr[i].param) {
          b1 = i;
        }
      } else if (arr[i].type == 1) {
        if (b2 == -1 || arr[b2].param < arr[i].param) {
          b2 = i;
        }
      } else {
        if (b3 == -1 || arr[b3].param < arr[i].param) {
          b3 = i;
        }
      }
    }
    cout << arr[b1].name << " " << arr[b1].size << " ";
    output(arr[b1].name);
    cout << endl;
    cout << arr[b2].name << " " << arr[b2].size << " ";
    output(arr[b2].name);
    cout << endl;
    cout << arr[b3].name << " " << arr[b3].size << " ";
    output(arr[b3].name);
    cout << endl;
  } else {
    sort(arr, arr + n);
    sort(r1, r1 + q1);
    sort(r2, r2 + q2);
    sort(r3, r3 + q3);
    int b1 = -1, b2 = -1, b3 = -1;
    for (int i = 0; i < n; i++) {
      if (arr[i].type == 0) {
        for (int j = 0; j < min(q1, arr[i].size); j++) {
          arr[i].param += r1[j].tough;
        }
        if (b1 == -1 || arr[i].param > arr[b1].param) {
          b1 = i;
        }
      } else if (arr[i].type == 1) {
        for (int j = 0; j < min(q2, arr[i].size); j++) {
          arr[i].param += r2[j].tough;
        }
        if (b2 == -1 || arr[i].param > arr[b2].param) {
          b2 = i;
        }
      } else if (arr[i].type == 2) {
        for (int j = 0; j < min(q3, arr[i].size); j++) {
          arr[i].param += r3[j].tough;
        }
        if (b3 == -1 || arr[i].param > arr[b3].param) {
          b3 = i;
        }
      }
    }
    int l1 = max(0, q1 - arr[b1].size);
    int l2 = max(0, q2 - arr[b2].size);
    int l3 = max(0, q3 - arr[b3].size);
    int bf1 = arr[b1].size, bf2 = arr[b2].size, bf3 = arr[b3].size;
    cout << arr[b1].name << " " << min(arr[b1].size, q1 + l2 + l3) << " ";
    for (int i = 0; i < min(arr[b1].size, q1); i++) {
      cout << r1[i].name << " ";
    }
    while (arr[b1].size > q1 && l2 != 0) {
      cout << r2[bf2 + l2 - 1].name << " ";
      arr[b1].size--;
      l2--;
    }
    while (arr[b1].size > q1 && l3 != 0) {
      cout << r3[bf3 + l3 - 1].name << " ";
      arr[b1].size--;
      l3--;
    }
    cout << endl;
    cout << arr[b2].name << " " << min(arr[b2].size, q2 + l1 + l3) << " ";
    for (int i = 0; i < min(arr[b2].size, q2); i++) {
      cout << r2[i].name << " ";
    }
    while (arr[b2].size > q2 && l1 != 0) {
      cout << r1[bf1 + l1 - 1].name << " ";
      arr[b2].size--;
      l1--;
    }
    while (arr[b2].size > q2 && l3 != 0) {
      cout << r3[bf3 + l3 - 1].name << " ";
      arr[b2].size--;
      l3--;
    }
    cout << endl;
    cout << arr[b3].name << " " << min(arr[b3].size, q3 + l1 + l2) << " ";
    for (int i = 0; i < min(arr[b3].size, q3); i++) {
      cout << r3[i].name << " ";
    }
    while (arr[b3].size > q3 && l1 != 0) {
      cout << r1[bf1 + l1 - 1].name << " ";
      arr[b3].size--;
      l1--;
    }
    while (arr[b3].size > q3 && l2 != 0) {
      cout << r2[bf2 + l2 - 1].name << " ";
      arr[b3].size--;
      l2--;
    }
    cout << endl;
  }
  return 0;
}
