n = int(input())
coins = sorted(list(map(int, input().split())), reverse=True)
for i in range(n + 1):
    if sum(coins[:i]) > sum(coins)/2:
        print(i)
        break
