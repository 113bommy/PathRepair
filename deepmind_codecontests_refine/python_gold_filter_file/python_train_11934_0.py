import math


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


n = int(input())
arr = [int(i) for i in input().split()]
ones = 0
for i in range(n):
    if arr[i] == 1:
        ones += 1
if ones > 0:
    print(n - ones)
else:
    ans = 10000000000
    for i in range(n):
        a1 = arr[i]
        count = 0
        for j in range(i+1, n):
            a1 = gcd(a1, arr[j])
            count += 1
            if a1 == 1:
                ans = min(ans, n+count-1)
                break
    if ans == 10000000000:
        print(-1)
    else:
        print(ans)