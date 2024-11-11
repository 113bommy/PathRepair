#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
template <class T>
T gcd(T x, T y) {
  while (T t = x % y) x = y, y = t;
  return y;
}
const double eps = 1e-9;
const double PI = acos(-1.);
const int INF = 1000000000;
const int MOD = 1000000007;
const double E = 2.7182818284590452353602874713527;
bool isdig(char x) { return x >= '0' && x <= '9'; }
bool isup(char x) { return x >= 'A' && x <= 'Z'; }
bool isdown(char x) { return x >= 'a' && x <= 'z'; }
bool islet(char x) { return isup(x) || isdown(x); }
char s[100][1000] = {"1.George Washington 乔治·华盛顿: 1789-1797",
                     "2.John Adams 约翰·亚当斯: 1797-1801",
                     "3.Thomas Jefferson 托马斯·杰斐逊 : 1801-1809",
                     "4.James Madison 詹姆斯·麦迪逊: 1809-1817",
                     "5.James Monroe 詹姆斯·门罗: 1817-1825",
                     "6.John Quincy Adams 约翰·昆西·亚当斯 : 1825-1829",
                     "7.Andrew Jackson 安德鲁·杰克逊: 1829-1837",
                     "8.Martin Van Buren 马丁·范布伦: 1837-1841",
                     "9.William Henry Harrison 威廉亨利·哈里森: 1841-1810.John "
                     "Tyler 约翰·泰勒: 1841-1845",
                     "10.John Tyler 约翰·泰勒: 1841-1845",
                     "11.James K. Polk 詹姆斯·波尔克: 1845-1849",
                     "12.Zachary Taylor 扎卡里·泰勒: 1849-1850",
                     "13.Millard Fillmore 米勒德·菲尔莫尔: 1850-1853",
                     "14.Franklin Pierce 富兰克林·皮尔斯: 1853-1857",
                     "15.James Buchanan 詹姆斯·布坎南: 1857-1861",
                     "16.Abraham Lincoln 亚伯拉罕·林肯: 1861-1865",
                     "17.Andrew Johnson 安德鲁·约翰逊: 1865-1869",
                     "18.Ulysses S. Grant 尤利塞斯·格兰特: 1869-1877",
                     "19.Rutherford B. Hayes 拉塞福德·海斯: 1877-1881",
                     "20.James A. Garfield 詹姆斯·加菲尔德: 1881-1881",
                     "21.Chester A. Arthur 切斯特·阿瑟: 1881-1885",
                     "22.Grover Cleveland 格罗弗·克利夫兰: 1885-1889",
                     "23.Benjamin Harrison 本杰明·哈里森: 1889-1893",
                     "24.Grover Cleveland 格罗弗·克利夫兰: 1893-1897",
                     "25.William McKinley 威廉·麦金利 : 1897-1901",
                     "26.Theodore Roosevelt 西奥多·罗斯福: 1901-1909",
                     "27.William Howard Taft 威廉·塔夫脱: 1909-1913",
                     "28.Woodrow Wilson 伍德罗·威尔逊: 1913-1921",
                     "29.Warren G. Harding 沃伦·哈定: 1921-1923",
                     "30.Calvin Coolidge 卡尔文·柯立芝: 1923-1929",
                     "31.Herbert C. Hoover 赫泊特·胡佛: 1929-1933",
                     "32.Franklin D. Roosevelt 富兰克林·罗斯福: "
                     "1933-1933.Harry S. Truman 哈里·杜鲁门: 1945-1953",
                     "33.Harry S. Truman 哈里·杜鲁门: 1945-1953",
                     "34.Dwight D. Eisenhower 德怀特·艾森豪威尔: "
                     "1953-1935.John F. Kennedy 约翰·肯尼迪: 1961-1963",
                     "35.John F. Kennedy 约翰·肯尼迪: 1961-1963",
                     "36.Lyndon B. Johnson 林顿·约翰逊: 1963-1969",
                     "37.Richard M. Nixon 理查德·尼克松: 1969-1974",
                     "38.Gerald Ford 杰拉尔德·福特: 1974-1977",
                     "39.Jimmy Carter 小詹姆斯·卡特: 1977-1981",
                     "40.Ronald Reagan 罗纳德·里根 : 1981-1989"};
int a, b;
void get_data() {
  cin >> a;
  a--;
}
void p(char x[]) {
  char str[10][100];
  sscanf(x, "%s%s%s%s%s", str[0], str[1], str[2], str[3], str[4]);
  for (int i = 1; i <= 4; i++) {
    if (str[i][0] < 0) break;
    if (str[i][strlen(str[i]) - 1] == '.') continue;
    printf("%s ", str[i]);
  }
  printf("\n");
}
void run() { p(s[a]); }
int main() {
  get_data();
  run();
  return 0;
}
