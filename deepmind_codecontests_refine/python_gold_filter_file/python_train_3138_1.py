
from math import sqrt

def ret(n):
    ans = set()
    for i in range(1,int(sqrt(n))+1):
        if n%i == 0:
            ans.add(i)
            ans.add(n//i)
    return ans


n = int(input())
l = list(map(int,input().split()))
mini = sum(l)
z1 = sum(l)
l.sort()
z = ret(l[0])
for j in z:
    k = z1-(l[0]+l[1])
    k+=l[0]//j+l[1]*j
    if k>=0:
     if k<mini:
        mini = k


for i in range(1,n):
    z = ret(l[i])
    for j in z:
      k = z1-(l[0]+l[i])
      if k>=0:
       k+=l[0]*j+l[i]//j
       if k<mini:
          mini = k


print(mini)



