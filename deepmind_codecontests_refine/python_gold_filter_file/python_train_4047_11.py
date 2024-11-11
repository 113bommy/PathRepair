n, *a = map(int, open(0).read().split())

ans = prev = 0
for i in a:
        tmp, prev = divmod(i+prev, 2)
        ans += tmp
        if i==0: prev=0
print(ans)