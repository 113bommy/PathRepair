n=int(input())
a=list(map(int,input().split()))
a.sort(reverse=True)

ans=a[0]
for i in range(2,len(a)):
    ans+=(a[(i)//2])
print(ans)
