def main():
    n = int(input())
    w1 = list(map(int,input().split()))
    w2 = list(map(int,input().split()))
    v1 = [0,0,0]
    for i in range(3):
        v1[i] = w2[i] - w1[i]
    dp1 = [0] * (n+1)
    for i in range(n):
        p = 0
        q = 0
        r = 0
        if i+1 - w1[0] >= 0:
            p = dp1[i+1 - w1[0]] + v1[0]
        if i+1 - w1[1] >= 0:
            q = dp1[i+1 - w1[1]] + v1[1]
        if i+1 - w1[2] >= 0:
            r = dp1[i+1 - w1[2]] + v1[2]
        dp1[i+1] = max(p,q,r,dp1[i])
    m = dp1[-1] + n

    v2 = [0,0,0]
    for i in range(3):
        v2[i] = w1[i] - w2[i]
    dp2 = [0] * (m+1)
    for i in range(m):
        p = 0
        q = 0
        r = 0
        if i+1 - w2[0] >= 0:
            p = dp2[i+1 - w2[0]] + v2[0]
        if i+1 - w2[1] >= 0:
            q = dp2[i+1 - w2[1]] + v2[1]
        if i+1 - w2[2] >= 0:
            r = dp2[i+1 - w2[2]] + v2[2]
        dp2[i+1] = max(p,q,r,dp2[i])
    print(m + dp2[-1])
    
if __name__ == "__main__":
    main()