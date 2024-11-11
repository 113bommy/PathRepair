n = int(input())
answ = 1
for x in range(n, n - 5, -1):
    answ *= x;
print(answ ** 2 // 120)