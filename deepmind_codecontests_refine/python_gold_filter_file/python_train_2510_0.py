n=int(input())

import math
def primeFactors(n):
    # Print the number of two's that divide n
    ans={}
    while n % 2 == 0:
        if 2 in ans:
            ans[2]+=1
        else:
            ans[2]=1
        n = n // 2

    # n must be odd at this point
    # so a skip of 2 ( i = i + 2) can be used
    for i in range(3, int(math.sqrt(n)) + 1, 2):

        # while i divides n , print i ad divide n
        while n % i == 0:
            if i in ans:
                ans[i]+=1
            else:
                ans[i]=1
            n = n // i
    if n > 2:
        if n in ans:
            ans[n]+=1
        else:
            ans[n]=1
    return ans



ans=1
ns=primeFactors(n)
# print(ns)
for i in ns.keys():
    ans*=ns[i]+1
print(ans)
