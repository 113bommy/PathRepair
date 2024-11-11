n = int(input())-1
from math import sqrt
k = int(sqrt(n*2)-1)
while(k*(k+1)/2<=n):
    k+=1
k-=1
print(n-k*(k+1)//2+1)