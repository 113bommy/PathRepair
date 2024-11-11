A = [int(input()) for i in range(5)]
d = 10
ans = 0
for a in A:
    ans += 0--a//10*10
    if a%10:
        d = min(d,a%10)
print(ans - 10 + d)
