n=int(input())
a=list(map(int,input().split()))

a.sort()
count1=0
count2=0
for i in range(n-1):
    count1+=a[i]
    if 2*count1<a[i+1]:
        count2=i+1
print(n-count2)

