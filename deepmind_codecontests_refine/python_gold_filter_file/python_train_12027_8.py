n = int(input())
ans = 1
for i in range(5):
    ans *= (n - i)**2
ans //= 120
print(ans)
