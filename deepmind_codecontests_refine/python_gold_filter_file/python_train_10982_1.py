def isPrime(i):
    if i == 2:
        return True
    for k in range(2,i):
        if i % k == 0:
            return False
    return True

n = int(input())

cnt = 0
ans = []

if n == 1:
    print(0)
    print('')
else:
    for i in range(2,n+1):
        if isPrime(i):
            k = i
            while k <= n:
                cnt += 1
                ans.append(k)
                k = k*i
    print(cnt)
    print(' '.join(map(str,ans)))

