from sys import stdin
from math import sqrt
n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))

a = sorted(a)
min_element = a[0]
a_sum = sum(a)
ans = a_sum
for i in range(1, n):
    for j in range (1, a[i] + 1):
        if a[i] % j == 0:
            cur_ans = a_sum - min_element - a[i] + min_element * j + a[i] / j
            ans = min(ans, cur_ans)
print(int(ans))