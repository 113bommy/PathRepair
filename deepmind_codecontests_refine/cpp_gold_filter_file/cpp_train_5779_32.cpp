#include <bits/stdc++.h>
template <typename T>
void UpdateMin(T& a, const T b) {
  a = std::min(a, b);
}
template <typename T>
void UpdateMax(T& a, const T b) {
  a = std::max(a, b);
}
static const long double Eps = 1.0e-09;
template <typename T>
bool IsEqual(const T a, const T b) {
  return std::abs(a - b) < Eps;
}
template <typename T>
bool IsGreater(const T a, const T b) {
  return a > b + Eps;
}
template <typename T>
bool IsLess(const T a, const T b) {
  return a + Eps < b;
}
template <typename T>
std::string ToStr(const T& val) {
  std::ostringstream ostr;
  ostr << val;
  return ostr.str();
}
template <typename T>
bool FromStr(const std::string& str, T& val) {
  std::istringstream istr(str);
  istr >> val;
  return !!istr;
}
template <typename T>
std::istream& operator>>(std::istream& ist, std::vector<T>& data) {
  ;
  for (size_t i = 0; i < data.size(); i++) {
    ist >> data[i];
  }
  return ist;
}
template <typename T>
T Read(std::istream& ist) {
  ;
  T val;
  ist >> val;
  return val;
}
template <typename T>
std::ostream& operator<<(std::ostream& ost, const std::vector<T>& data) {
  for (size_t i = 0; i < data.size(); i++) {
    if (i != 0) {
      ost << ' ';
    }
    ost << data[i];
  }
  return ost;
}
template <size_t id>
class StopWatch {};
const uint32_t MaxBruteForceVal = 1000000;
bool IsPrime(const uint32_t z) {
  if (z < 2) return false;
  for (uint64_t p = 2; p * p <= z; p++) {
    if (z % p == 0) return false;
  }
  return true;
}
bool TryBruteForce(const uint32_t z, std::vector<uint32_t>& numbers) {
  numbers.clear();
  if (IsPrime(z)) {
    numbers.push_back(z);
    return true;
  };
  if (IsPrime(z - 2)) {
    numbers.push_back(2);
    numbers.push_back(z - 2);
    return true;
  }
  const size_t mx = 40;
  for (size_t a = 0; a < mx; a++) {
    const uint32_t va = a;
    if (!IsPrime(va)) continue;
    for (size_t b = 0; b < mx; b++) {
      const uint32_t vb = b;
      if (!IsPrime(vb)) continue;
      for (size_t c = 0; c < mx; c++) {
        const uint32_t vc = c;
        if (!IsPrime(vc)) continue;
        if (va + vb + vc == z) {
          numbers.push_back(va);
          numbers.push_back(vb);
          numbers.push_back(vc);
          return true;
        }
      }
    }
  }
  return false;
}
std::vector<uint32_t> GetAns(const uint32_t z) {
  std::vector<uint32_t> numbers;
  if (TryBruteForce(z, numbers)) return numbers;
  numbers.clear();
  numbers.push_back(3);
  const uint32_t x = z - 3;
  const uint32_t mid = x / 2;
  for (uint32_t i = 1; i < mid; i++) {
    {
      const uint32_t vb = mid - i;
      const uint32_t vc = mid + i;
      if (IsPrime(vb) && IsPrime(vc)) {
        numbers.push_back(vb);
        numbers.push_back(vc);
        return numbers;
      }
    }
    {
      const uint32_t vb = i;
      const uint32_t vc = x - i;
      if (IsPrime(vb) && IsPrime(vc)) {
        numbers.push_back(vb);
        numbers.push_back(vc);
        return numbers;
      }
    }
  }
  return std::vector<uint32_t>();
}
bool Solve(std::istream& ist, std::ostream& ost, const bool multipleTestMode) {
  StopWatch<1> sw;
  (void)sw;
  uint32_t n;
  ist >> n;
  if (multipleTestMode && !ist) return false;
  const std::vector<uint32_t> ans = GetAns(n);
  ost << ans.size() << std::endl;
  ost << ans << std::endl;
  ;
  for (size_t i = 0; i < ans.size(); i++) {
    ;
  }
  return multipleTestMode;
}
int main(int argc, const char* argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::istream* ist = &std::cin;
  std::ostream* ost = &std::cout;
  std::unique_ptr<std::istream> fileInput;
  if (argc > 1) {
    fileInput.reset(new std::ifstream(argv[1]));
    if (!(*fileInput)) {
      std::cout << "File not found: " << argv[1] << std::endl;
    }
    ist = fileInput.get();
  }
  Solve(*ist, *ost, false);
}
