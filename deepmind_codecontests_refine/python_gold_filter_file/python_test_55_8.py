k = int(input())

module = 10**9 + 7
ans = 6
for num in range(1, k):
    ans = (ans * pow(4, pow(2, num), module)) % module

print(ans)
