money = int(input())
change = [money, 0, 0, 0, 0]

for value, currency in enumerate((100, 20, 10, 5)):
    change[value], change[value+1] = divmod(change[value], currency)

print(sum(change))