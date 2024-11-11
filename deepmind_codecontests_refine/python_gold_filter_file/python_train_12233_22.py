n = int(input())
div = {}
for i in range(2, 1000001):
    if n == 1: break
    if n % i == 0: div[i] = 0
    while n % i == 0:
        div[i] += 1
        n //= i
if n > 1: div[n] = 1
ans = 1
for k, i in div.items():
    ans = ans * k
print(ans)
