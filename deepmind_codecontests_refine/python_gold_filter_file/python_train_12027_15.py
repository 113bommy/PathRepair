n = int(input())
ans = 1
for i in range(5):
    ans *= (n-i)*(n-i)
print(ans//120)