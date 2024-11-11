import math
def solve():
    m,n = input().strip().split()
    m = int(m); n = int(n)
    ans = 0.0
    for i in range(0, m + 1):
        ans += i * (pow(i/m, n) - pow((i - 1)/m, n))
    return ans
 
print(solve())