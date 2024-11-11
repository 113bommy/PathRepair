from collections import *

s = input()
numbers = list(map(int, s.split()))
n = numbers[0]
k = numbers[1]
#print(n, k)
s=input().split()
c=defaultdict(int)
for i in s:
    c[int(i)]+=1
#print(c)
a=max(c[i] for i in c)
a=((a-1)//k+1)*k
print(a*len(c.keys())-n)