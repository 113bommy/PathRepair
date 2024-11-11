import bisect
n = int(input())
l = sorted(list(map(int, input().split())))
ans=0
for i in range(n-2):
    for j in range(i+1,n-1):
        ans+=bisect.bisect_left(l[j+1:], l[i] + l[j])
print(ans)  