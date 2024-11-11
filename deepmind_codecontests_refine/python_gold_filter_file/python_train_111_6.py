from math import ceil
n=int(input())
p=[int(x) for x in input().split()]
s=sum(p)
m=max(p)
print(max(m,(2*s//n)+1))






