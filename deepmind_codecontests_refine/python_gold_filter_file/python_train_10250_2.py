n, k = map(int, input().split())
counter = {}

for ch in input():
    counter[ch] = counter.get(ch, 0) + 1

sorted_counts = sorted(counter.values(), reverse=True)
tmp_cards = coins = 0
for card_count in sorted_counts:
    tmp_sum = tmp_cards + card_count
    if tmp_sum < k:
        tmp_cards = tmp_sum
        coins += card_count * card_count
    else:
        partial = card_count-(tmp_sum-k)
        coins += partial * partial
        print(coins)
        break