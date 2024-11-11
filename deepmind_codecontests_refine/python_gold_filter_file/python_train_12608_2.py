
def getPrimes(a):
    ret = []
    i = 1;
    while (i*i <= a):
        if (a%i == 0):
            ret.append(i)
            j = a//i
            if (i != j):
                ret.append(j)
        i += 1
    ret.reverse()
    # print(ret)
    return ret
n = int(input())
l = list(map(int,input().split()))
mod = 1000000007
arr = [0]*(1000001)
arr[0] = 1

ans = 0
dp = [0]*(max(l)+2)
dp[0] = 1


for i in range(n):
    primes = getPrimes(l[i])
    
    # primes.sort()
    # primes.reverse()
    for j in primes:
            dp[j]+=dp[j-1]
print((sum(dp)-1)%mod)
       
