import sys
def ints():
    return list(map(int, sys.stdin.readline().strip().split()))
tc = 1
while tc:
    tc-=1
    ans = 99999999999999
    ith = 99999999999999
    n, t= map(int, input().split())
    for i in range(n):
        a, b = map(int, input().split())
        if a >= t and ans > a:
            ans = a
            ith = i
        elif a < t:
            val = t-a
            new = val/b
            if new == int(new):
                new = int(new)
            else:
                new = int(new)+1
            if (a + b*new) < ans:
                ans = (a + b*new)
                ith = i
    print(ith+1)