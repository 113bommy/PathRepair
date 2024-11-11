n=int(input())
x=[]
c=1
for i in range(n):
    x.append(int(input()))
for i in range(len(x)-1):
    if (x[i]!=x[i+1]):
        c=c+1
print(c)