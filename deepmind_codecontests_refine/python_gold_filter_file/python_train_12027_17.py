n = int(input())
ans = 1
for i in range(5): ans *= n - i
print(int(ans / 120) * ans)