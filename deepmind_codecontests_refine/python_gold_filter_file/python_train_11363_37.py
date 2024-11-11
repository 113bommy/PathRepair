N = int(input()) + 2
ans = 0
for i in range(1, N - 3):
   ans += (i + 1) * (i + 2)
print(ans)