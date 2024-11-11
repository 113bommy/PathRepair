import math
a=int(input())
k=sorted(list(map(int,input().split())))
c=0
for i in range(len(k)):
    if i%2==0:
        c+=k[i]**2
    else:c-=k[i]**2
print( abs(c*(math.pi)))


