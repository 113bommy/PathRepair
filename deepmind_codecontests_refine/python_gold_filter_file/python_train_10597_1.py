def main():
    N,M=map(int,input().split())
    L=2**N
    dp=[10**10 for i in range(L)]
    dp[0]=0


    for i in range(M):
        a, _ = map(int, input().split())
        key=sum([2**(int(i)-1) for i in input().split()])
        for j in range(L):
                q=j|key
                dp[q]=min(dp[j]+a,dp[q])


    ans=dp[L-1]
    print(ans if ans<10**10 else -1)

if __name__ == '__main__':
    main()