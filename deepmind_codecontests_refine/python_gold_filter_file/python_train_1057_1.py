sasha, masha, price = map(int, input().split())
total = (sasha + masha) // price
remSasha = sasha % price
remMasha = masha % price
together = (remSasha + remMasha) // price * price
give = min(together - remSasha, together - remMasha)
print(total, max(give, 0))