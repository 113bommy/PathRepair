c = 0
n,m = map(int, input().split())
for i in range(n):
    a = list(map(int, input().split()))
    j = 0
    while j<2*m:
        if j%2==0 and a[j]==1:
            c+=1
            j+=2
        elif j%2==1 and a[j]==1:
            c+=1
            j+=1
        else:
            j+=1
print(c)