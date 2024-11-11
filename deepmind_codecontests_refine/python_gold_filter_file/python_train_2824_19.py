n,k=[int(i) for i in input().split()]
a=list(map(int,input().split()))
aa=1
c=1
for i in range(len(a)-1):
    if  a[i]!=a[i+1]:
        aa+=1
        if aa>c:
            c=aa
    else:
        aa=1
print(c)