n = int(input())
res = [0] * 6
res[4] = n % 2
n //= 2
res[1] = n % 2
n //= 2
res[3] = n % 2
n //= 2
res[2] = n % 2
n //= 2
res[0] = n % 2
n //= 2
res[5] = n % 2

d = 1
ans = 0
for i in res:
    if i:
        ans += d
    d *= 2

print(ans)

