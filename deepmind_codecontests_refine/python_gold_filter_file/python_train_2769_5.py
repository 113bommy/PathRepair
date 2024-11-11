A, B = [int(i) for i in input().split()]
j = min(A, B)
i = 1
ans = 1
while i <= j:
    ans *= i
    i += 1
print(ans)