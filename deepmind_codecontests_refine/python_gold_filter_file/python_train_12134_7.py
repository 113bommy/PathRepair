n=int(input())
l=list(map(int,input().split()))
count=1
z=1
for i in range(n-1):
    if l[i+1]>l[i]:
        count+=1
    else:
        count=1
    z=max(z,count)
print(z)