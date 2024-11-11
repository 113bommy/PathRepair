#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long int l = v.size();
  for (long long int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
long long int gcd(long long int a, long long int b) {
  if (b < a) {
    swap(a, b);
  }
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b / gcd(a, b));
}
long long int primefactorise(int n) {
  if (n == 1) {
    return 1;
  }
  long long int ans = n;
  while (n % 2 == 0) {
    n = n / 2;
    if (n != 1) {
      ans += n;
    }
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      n = n / i;
      if (n != 1) {
        ans += n;
      }
    }
  }
  ans += 1;
  return ans;
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans = ans;
    }
    b /= 2;
    a *= a;
    a = a;
  }
  return ans;
}
vector<long long int> getbinary(long long int x, long long int size) {
  vector<long long int> bin(size, 0);
  long long int iter = 0;
  while (x > 0) {
    if (x % 2 == 0) {
      bin[iter] = 0;
    } else {
      bin[iter] = 1;
    }
    x /= 2;
    iter++;
  }
  return bin;
}
long long int dist(pair<long long int, long long int> a,
                   pair<long long int, long long int> b) {
  return 0;
}
vector<long long int> getprimes() {
  vector<long long int> primes(1000000, 0);
  vector<long long int> ans;
  for (int i = 2; i < 1000000; i++) {
    if (primes[i] == 0) {
      for (int j = 2 * i; j < 1000000; j += i) {
        primes[j] = 1;
      }
      ans.push_back(i);
    }
  }
  return ans;
}
const long long int size = 10;
struct tnode {
  tnode* child[size];
  long long int isword;
};
tnode* makenode() {
  tnode* temp = new tnode;
  for (int i = 0; i < size; i++) {
    temp->child[i] = NULL;
  }
  temp->isword = 0;
  return temp;
}
void insert(tnode* root, string second) {
  tnode* temp = root;
  for (int i = 0; i < second.size(); i++) {
    long long int key = second[i] - 'a';
    if (temp->child[key] == NULL) {
      temp->child[key] = makenode();
    }
    temp = temp->child[key];
  }
  temp->isword = 1;
}
long long int search(tnode* root, string second) {
  tnode* temp = root;
  for (int i = 0; i < second.size(); i++) {
    long long int key = second[i] - 'a';
    if (temp->child[key] == NULL) {
      return 0;
    }
    temp = temp->child[key];
  }
  return temp->isword;
}
int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  long long int ans;
  cin >> ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(50);
  cout.flush();
  long long int a = 0, b = 0, maxnum = query(0, 0);
  for (int i = 2; i >= 0; i--) {
    long long int temp1 = query(a ^ power(2, i), b);
    long long int temp2 = query(a, b ^ power(2, i));
    if (temp1 == temp2) {
      if (maxnum == 1) {
        a ^= power(2, i);
      } else {
        b ^= power(2, i);
      }
      maxnum = temp1;
    } else {
      if (temp2 == 1) {
        a ^= power(2, i);
        b ^= power(2, i);
      }
    }
  }
  cout << "! " << a << " " << b << endl;
}
