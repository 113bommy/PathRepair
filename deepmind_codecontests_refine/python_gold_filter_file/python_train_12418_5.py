import math
# import sys
# sys.stdin = open("input.txt", 'r')
# sys.stdout = open('output.txt', 'w')

for z in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if n <= 2:
        i = 0
        l = 0
        while (i <= k*n-1):
            l += a[i]
            i += n
        print(l)
    else:
        d = math.ceil(n/2) if n % 2 != 0 else math.ceil(n/2)+1
        i = k*(n-d)
        l = 0
        while (i < n*k-1):
            l += a[i]
            i += d
        print(l)
