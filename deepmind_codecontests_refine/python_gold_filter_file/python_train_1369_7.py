n = int(input())
a = list(map(int,input().split()))
c=0
i=0
while(i<n):
    m=a[i]
    while(i!=m-1):
        i+=1
        if(m<a[i]):
            m=a[i]
    c+=1
    i+=1
print(c)