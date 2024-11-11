cards_left = int(input().split()[1])
deck = input()
coins = [deck.count(card) for card in set(deck)]
coins.sort(reverse=True)
result = 0

for coin in coins:
    if cards_left > coin:
        result += coin ** 2
        cards_left -= coin
    else:
        result += cards_left ** 2
        break

print(result)
