from collections import defaultdict

H, W, N = map(int, input().split())
sr, sc = map(int, input().split())
S = input()
T = input()

def solve() :
    l, r = 1, W
    d, u = 1, H
    
    for i in range(N - 1, -1, -1) :
        if T[i] == 'L' :
            r = min(r + 1, W)
        elif T[i] == 'R' :
            l = max(l - 1, 1)
        elif T[i] == 'D' :
            u = min(u + 1, H)
        elif T[i] == 'U' :
            d = max(d - 1, 1)
            
        if S[i] == 'L' :
            l += 1
        elif S[i] == 'R' :
            r -= 1
        elif S[i] == 'D' :
            d += 1
        elif S[i] == 'U' :
            u -= 1
            
        if r < l or u < d :
            return 'NO'

    if l <= sc <= r and d <= H + 1 - sr <= u :
        return 'YES'
    else :
        return 'NO'
    
print(solve())
