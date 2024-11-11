n,t = input().strip().split()
n = int(n)
t = int(t)
a = input().strip().split()
for index,item in enumerate(a):
    a[index] = int(item)
i = 0
j = 0
s = 0
ans = 0
while j < n:
    s += a[j]
    if s <= t:
        ans = max(ans,j-i+1)
    else:
        while s > t:
            s -= a[i]
            i += 1
    j += 1
print(ans)