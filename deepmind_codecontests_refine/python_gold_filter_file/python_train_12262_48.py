import math

K=int(input())

ans=0
for i in range(K):
    for j in range(K):
        for k in range(K):
            ans+=math.gcd(math.gcd(j+1,k+1),i+1)

print(ans)