def solve(a,b,c,d):
    ans = 0
    for x in range(a, b+1):
        y_s = max(b, c-x+1)
        y_e = max(min(d+1-x, c), y_s)
        t_s, t_e = min(y_s+x-1, d)-c+1, min(y_e+x-1, d)-c+1
        ans += (t_s+t_e) * (y_e-y_s+1)//2
        if y_e < c:
            ans += (c-y_e)*(d-c+1)
    return ans

a,b,c,d = list(map(int, input().split()))
print(solve(a,b,c,d ))
