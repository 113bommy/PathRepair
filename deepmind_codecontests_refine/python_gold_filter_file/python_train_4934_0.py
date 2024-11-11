from itertools import *
import sys
m=[32,29,32,31,32,31,32,32,31,32,31,32]
s,t=[map(int,input().split('.')) for _ in range(2)]
g=False
a,b,c=s
for d,e,f in permutations(t):
 g|=b<13 and e<13 and a<m[b-1]+(b==2)*(c%4==0)and d<m[e-1]+(e==2)*(f%4==0)and(c-f>18 or(c-f==18 and(b>e or(b==e and(a>=d)))))
print(["NO","YES"][g])