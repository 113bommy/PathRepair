from math import gcd

K=int(input())+1
sum=0

for i in range(1,K):
  for j in range(1,K):
    for k in range(1,K):
       sum+=gcd(gcd(i,j),k)    
print(sum)