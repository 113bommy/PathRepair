import sys
input = sys.stdin.readline

def solve():
    a,b,c = map(int,input().split())
    mn = 1<<32
    ans = None
    for a0 in range(1,20001):
        for b0 in range(a0,20001,a0):
            m = c%b0
            if m != c:
                if m <= b0-m:
                    c0 = c-m
                else:
                    c0 = c + b0 - m
                cost = abs(a0-a) + abs(b0-b) + abs(c0-c)
            else:
                c0 = c + b0 - m
                cost = abs(a0-a) + abs(b0-b) + abs(c0-c)

            if cost < mn:
                mn = cost
                ans = a0,b0,c0
    print(mn)
    print(*ans)

for nt in range(int(input())):
    solve()
