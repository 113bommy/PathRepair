import sys
sys.setrecursionlimit(10**9)
#sys.stdin = open("inp.txt")

SCALE  = 10**6
def func(it):
    return float(SCALE * float(it))

def solve(c, m, p, v):
    ans = p/SCALE
    if c>0:
        if c>v:
            if m>0: ans += (c/SCALE) * (1 + solve(c-v, m+v/2, p+v/2, v))
            else:   ans += (c/SCALE) * (1 + solve(c-v, 0, p+v, v))
        else:
            if m>0: ans += (c/SCALE) * (1 + solve(0, m+c/2, p+c/2, v))
            else  : ans += (c/SCALE) * (1 + solve(0, 0, p+c, v))

    if m>0:
        if m>v:
            if c>0: ans += (m/SCALE) * (1 + solve(c+v/2, m-v, p+v/2, v))
            else:   ans += (m/SCALE) * (1 + solve(0, m-v, p+v, v))
        else:
            if c>0: ans += (m/SCALE) * (1 + solve(c+m/2, 0, p+m/2, v))
            else  : ans += (m/SCALE) * (1 + solve(0, 0, p+m, v))

    return ans

for case in range(int(input())):
    mp = map(func, input().split())
    ans = solve(*mp)
    #n = int(input())
    #a, b = map(int, input().split())
    #li = list(map(int, input().split()))
    print(round(ans, 12))
