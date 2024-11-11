n=int(input())
c=0;d=0
a=list(map(int,input().split()))
for i in range(n):
    if a[i]==i:
        c+=1
    else:
            if a[a[i]]==i:
                d=1
print(c+d+int(c!=n))      