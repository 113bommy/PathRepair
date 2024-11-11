n=int(input())
a=list(map(int,input().split()))
a.sort()
for i in range(1,len(a)):
    a[i]+=1
a[0]=max(1,a[0]-1)
for i in range(1,len(a)):
    if a[i]-2>a[i-1]:
        a[i]=a[i]-2
    elif a[i]-1>a[i-1]:
        a[i]=a[i]-1
    else:
        pass
c=1
x=a[0]
for i in a:
    if i==x:
        pass
    else:
        c+=1
        x=i
print(c)