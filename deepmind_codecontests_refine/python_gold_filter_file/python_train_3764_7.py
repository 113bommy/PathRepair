# a+b, a+c, b+c and a+b+c.
a=list(map(int,input().split()))
k=max(a)
j=a.index(k)
for i in range(len(a)):
    if(i!=j):
        print(k-a[i],end=" ")
    
