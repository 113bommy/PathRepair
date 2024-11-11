n = int(input())
ost = n//2520
ans = 0
for i in range(1, n%2520 + 1):
    if i % 2 == 0 or i % 3 == 0 or i % 5 == 0 or i % 7 == 0:
        ans += 1
print(ost * 576 + n%2520 - ans)
