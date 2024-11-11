import math

def prime_division(n):
    ans = []
    m = int(n ** 0.5)
    i = 2
    while i <= m:
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                n //= i
                cnt += 1
            ans.append((i, cnt))
            m = int(n ** 0.5)
        i += 1
    if n != 1:
        ans.append((n, 1))
    return ans

#  aabaaba  count+(N-1) C (N-1)

N,M=map(int,input().split())
pms=prime_division(M)
ans = 1
for pm in pms:
    #print(pm)
    ans *= math.factorial(pm[1]+(N-1)) // (math.factorial(pm[1]) * math.factorial(N-1))

print(ans % (10 ** 9 + 7))
