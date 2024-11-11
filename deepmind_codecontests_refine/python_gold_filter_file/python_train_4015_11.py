n=int(input())
a=list(map(str,input().split("W")))
x=[]
for i in range(0,len(a)):
    if len(a[i])>0:
        x.append(len(a[i]))
print(len(x))
print(*x)
