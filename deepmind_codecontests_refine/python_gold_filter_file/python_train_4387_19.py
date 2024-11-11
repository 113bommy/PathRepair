on_table = input()
cards = input()
first = cards.find(on_table[0])
second = cards.find(on_table[1])
if first >= 0 or second >= 0:
    print("YES")
else:
    print('NO')
