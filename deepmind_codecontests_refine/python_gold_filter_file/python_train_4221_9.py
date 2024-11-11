n = int(input())
ans = 0
while(n>0):
    if n % 8 == 1:
        ans += 1
    n //= 8
print(ans)