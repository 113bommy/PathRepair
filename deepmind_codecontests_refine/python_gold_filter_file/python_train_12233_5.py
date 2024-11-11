n = int(input())
i = 2
ans = 1
while(i*i <= n):
    if(n%i == 0):
        ans *= i
        while(n%i == 0):
            n //= i
    i += 1
if(n > 1):
    ans *= n
print(ans)
