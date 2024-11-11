a=[]
a=input().split("+")
a.sort()
n=len(a)
for i in range(n-1):
    print(a[i],end="")
    print("+",end="")
print(a[n-1])