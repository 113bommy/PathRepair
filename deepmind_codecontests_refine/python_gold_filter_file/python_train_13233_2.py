
n = int(input())

arr = list(map(int,input().strip().split()))

mp = {}

s = 0
for i in range(n):
    if arr[i] not in mp:
        mp[arr[i]] = 1
    else:
        mp[arr[i]]+=1
    s+=arr[i]

ans = []
#print(s)
#print(mp)
for i in range(n):
    if (s-arr[i])%2==0:
        if ((s-arr[i])//2) in mp:
            if mp[arr[i]] >= 2 or arr[i]!=((s-arr[i])//2):
                ans.append(i+1)

if ans==[]:
    print(0)
else:
    print(len(ans))
    print(*ans)
