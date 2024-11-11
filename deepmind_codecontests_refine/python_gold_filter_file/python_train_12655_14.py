a, b = map(int , input().split())
s = list(map(int, input().split()))
count = 0
for i in range(a-1):
    k = s[i]+s[i+1]
    if b>k:
        l = max(s[i], s[i+1])
        s[i], s[i+1] = s[i], s[i+1]+b-k
        count += b-k
print(count)
print(*s, sep= " ")