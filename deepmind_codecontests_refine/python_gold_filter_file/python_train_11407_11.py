n, x = map(int,input().split())
a = list(map(int,input().split()))
cnt = [0]*int(1e6)
ans = 0
for val in a:
        ans+=cnt[val^x]
        cnt[val]+=1
print(ans)
