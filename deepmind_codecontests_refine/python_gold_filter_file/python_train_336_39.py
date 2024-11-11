def fact(n):
    if n==0:
        return(1)
    M = 10**9+7
    ans = 1
    for i in range(1,n+1):
        ans = ans*i
        ans%=M
    return(ans)


def ans(n):
    M = 10**9+7
    answer = fact(n)
    answer = answer%M
    answer -= (2**(n-1))%M
    answer = answer%M
    return(answer)


n = int(input())
print(int(ans(n)))