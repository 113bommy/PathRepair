n = int(input())

ans = 0
for i in range(2,int(n**0.5)+1):
    count = 1
    loop = 1
    while n % i == 0:
        n = int(n/i)
        count -= 1
        if count == 0:
            ans += 1
            loop += 1
            count = loop

if n > 1:
    ans += 1
print(ans)