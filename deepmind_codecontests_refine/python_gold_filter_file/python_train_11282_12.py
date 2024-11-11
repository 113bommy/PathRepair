n = list(input())
m = list(input())
ans = 0
for i in range(len(m)):
    if m[i] == n[ans]:
        ans += 1
print(ans+1)
