from math import gcd
N, M = map(int, input().split())
A = list(map(int, input().split()))
A = [i // 2 for i in A]
lcd = 1
for a in A:
    lcd *= a // gcd(lcd, a)
for a in A:
    if lcd // a % 2 == 0:
        print(0)
        exit()
print((M//lcd+1)//2)
