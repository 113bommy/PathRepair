res = ""
for _ in range(int(input())):
    n = int(input())
    ans = 1
    for i in range(3, 2*n+1):
        ans *= i
        ans %= 1000000007
    res += str(ans) + "\n"
print(res)





















