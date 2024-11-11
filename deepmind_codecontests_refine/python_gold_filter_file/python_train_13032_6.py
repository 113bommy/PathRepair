pr = [1] * 100000
primes = set()

for i in range(2, 100000):
    if pr[i]:
        primes.add(i)
        for j in range(i * i, 100000, i):
            pr[j] = 0











#amount of p's in m!
def apnf(p, m):
    cnt = 0
    while m:
        m //= p
        cnt += m
    return cnt
x, n = [int(i) for i in input().split()]
xx = x

myp = []
for p in primes:
    if xx % p == 0:
        while xx % p == 0:
            xx //= p
        myp.append(p)
if xx != 1:
    myp.append(xx)

# print(primes)
# print(myp)

mod = 1000000007
ans = 1 
for p in myp:
    exp = apnf(p, n)
    ans = (ans * pow(p, exp, mod))%mod


print(ans)



