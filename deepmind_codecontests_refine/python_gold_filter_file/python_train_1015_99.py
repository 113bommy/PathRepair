def main():
    n,k = map(int,input().split())
    a = []
    for _ in range(n):
        a.append(int(input()))
    DP = [[] for _ in range(n)]
    DP[1].append(0)
    M = 1
    for i in range(1,n):
        m = M
        flg = 0
        while m>0:
            for p in DP[m]:
                if abs(a[i]-a[p])<=k:
                    DP[m+1].append(i)
                    flg = 1
                    if m+1>M:
                        M=m+1
                    break
            if flg==1:
                break
            m -= 1
        if flg==0:
            DP[1].append(i)
    print(M)

if __name__ == "__main__":
    main()
