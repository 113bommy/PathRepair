coins_num = int(input())
coins = sorted(list(map(int, input().split())))
total_coins = sum(coins)
my_total = 0
for j, i in enumerate(reversed(coins)):
    my_total += i
    total_coins -= i
    if my_total > total_coins:
        print(j+1)
        exit()