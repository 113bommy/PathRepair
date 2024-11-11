n = int(input())
ans = 1
for i in range(5):
    ans *= n-i
print(ans**2//120)
