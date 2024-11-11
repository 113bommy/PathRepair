N = int(input())
for i in range(1, 1+int(N**(1/2))):
    if N%i == 0:
        ans = i - 1 + (N//i -1)
print(ans)