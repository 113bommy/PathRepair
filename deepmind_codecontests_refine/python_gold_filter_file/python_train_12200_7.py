n=int(input())
l=[]
for i in range(n):
    l.append(list(map(int,input().split())))
x=int(((l[0][1]*l[0][2])/l[1][2])**0.5)
d=[x]
for i in range(1,n):
    d.append(l[0][i]//x)
print(*d)
