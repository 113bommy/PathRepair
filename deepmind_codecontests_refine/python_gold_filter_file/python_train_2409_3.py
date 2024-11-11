n=int(input())
a=list(map(int,input().split(' ')))
m=max(a)
count=1
mi=1
for i in range(1,n):
    if a[i]==a[i-1] and a[i]==m:
        count+=1
    else:
        count=1
    if count>mi:
        mi=count
print(mi)
