def sieve(n):
    n += 1
    
    prime = [True] * n
    for i in range(2, n):
        if i * i > n:
            break
        if prime[i]:
            for j in range(i * i, n, i):
                prime[j] = False

    res = [0]
    for i in range(2, n):
        if prime[i]:
            res.append(i)
    
    return res

n = int(input())
a = list(map(int, input().split()))

cnt = [0] * 3
for i in a:
    cnt[i] += 1

primes = sieve(sum(a) + 1)

ans = []
for i in range(1, len(primes)):
    dist = primes[i] - primes[i - 1]

    take_two = min(dist // 2, cnt[2])
    take_one = min(dist - 2 * take_two, cnt[1])

    cnt[2] -= take_two
    cnt[1] -= take_one

    ans.extend([2] * take_two)    
    ans.extend([1] * take_one)

ans.extend([2] * cnt[2])    
ans.extend([1] * cnt[1])

for x in ans:
    print(x, end=" ")