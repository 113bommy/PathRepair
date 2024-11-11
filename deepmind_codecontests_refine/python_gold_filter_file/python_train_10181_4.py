def kazu(p, q):
    return max(p[0], q[0]), min(p[1], q[1]), max(-max(p[0], q[0]) + min(p[1], q[1]) + 1, 0)
def kazu1(p):
    return max(p[1] - p[0] + 1, 0)
def main():
    N = int(input())
    l = []
    for _ in range(N):
        L, R = map(int, input().split())
        l.append((L, R))
    l.sort(key=lambda x:x[1])
    dp= (l[0], l[1])
    for i in range(2, N):
        a, b, c = kazu(dp[0], l[i]) 
        d, e, f = kazu(dp[1], l[i])
        g, h, j = kazu(dp[0], dp[1])
        m = max(f + kazu1(dp[0]), c + kazu1(dp[1]), j + kazu1(l[i]))
        if  m == f + kazu1(dp[0]):
            dp = ((d,e),dp[0])
        elif m == c + kazu1(dp[1]):
            dp = ((a,b),dp[1])
        else:
            dp = ((g,h), l[i])
    return kazu1(dp[0]) + kazu1(dp[1])
print(main())
