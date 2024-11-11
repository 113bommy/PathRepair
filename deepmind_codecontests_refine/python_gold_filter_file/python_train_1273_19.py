import bisect

n=int(input())
l1 = list(map(int, input().split(' ')))
l2 = list(map(int, input().split(' ')))

diffs = []
for i in range(n):
    diffs.append(l1[i]-l2[i])

diffs = sorted(diffs)

ans=0
for i in range(n):
    if diffs[i]>0:
        ans += i-bisect.bisect_left(diffs, -diffs[i]+1)


print(ans)
