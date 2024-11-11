n = int(input())
arr = [i for i in range(n + 1)]
flags = [0 for i in range(n + 1)]
primes = []
for i in range(2, n + 1):
    if flags[i]:
        continue
    primes.append(i)
    for j in range(i * 2, n + 1, i):
        flags[j] = 1
ans = set()
for  number in primes:
    k = 1
    while number ** k <= n:
        ans.add(number ** k)
        k += 1
print(len(ans))
print(*ans)