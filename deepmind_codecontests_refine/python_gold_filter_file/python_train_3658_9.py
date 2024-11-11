# link: https://codeforces.com/problemset/problem/1110/C

from math import log, sqrt

for _ in range(int(input())):
    num = int(input())
    max_power = int(log(num, 2)) + 1
    if num == pow(2, max_power) - 1:
        max_b = 1
        for divisor in range(2, int(sqrt(num)) + 1):
            if num % divisor == 0:
                max_b = max(max_b, num // divisor)
        print(max_b)        
    else:
        print(pow(2, max_power) - 1)