def pol(n,k):
    if n == 0:
        return 1
    ans = 1
    for i in range(k):
        ans *= (n-i)/(i+1)
    k = int(ans)
    if abs(k - ans) < 1/2:
        return k
    return k + 1
n = int(input())
pr = pol(n,5) * pol(n,5) * 120
print(pr)