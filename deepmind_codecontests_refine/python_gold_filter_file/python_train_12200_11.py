import math
n=int(input())
l=[]
for i in range(n):
    l.append(list(map(int,input().split())))
x=l[0][1]
y=l[0][2]
z=l[1][2]
a2=math.sqrt(x*z//y)
a1=x//a2
a3=z//a2
print(int(a1),int(a2),int(a3),end=" ")
for j in range(n-3):
    print (int(l[0][j+3]//a1),end=" ")
print()
