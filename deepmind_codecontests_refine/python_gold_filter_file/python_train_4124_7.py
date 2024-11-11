n=int(input())
a=list(map(int,input().split()))

flag=True
f1=True
f2=False

for i in range(1,n):
    if f1:
        if a[i]<=a[i-1]:
            f1=False
            if a[i]<a[i-1]:
                f2=True
    else:
        if a[i]<a[i-1]:
            f2=True
        elif a[i]>a[i-1]:
            flag=False
        if f2:
            if flag and a[i]>=a[i-1]:
                flag=False

if flag:
    print("YES")
else:
    print("NO")
    
        
