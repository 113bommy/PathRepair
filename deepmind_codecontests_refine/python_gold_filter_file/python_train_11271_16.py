for i in range(int(input())):
    n=int(input())
    s=str(input())
    k=s[n-1]
    ans=""
    ans+=k
    ans+=k*(n-1)
    print(ans)