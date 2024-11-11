n,k = map(int, input().split())
a = list(map(int, input().split()))
ans, tmp = 0, 0
for i in range(len(a)):
    ans += (a[i]+tmp)//k
    rem = (a[i]+tmp)%k
    # print(a[i], tmp, rem, ans)
    if i == n-1:
        if rem:
            ans += 1
    elif rem > a[i]:
        tmp = 0
        ans += 1
    else:
        tmp = rem
print(ans)