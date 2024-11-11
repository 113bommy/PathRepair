discounts = int(input())
discount_values = list(map(int, input().split()))
target = int(input())
item_values = list(map(int, input().split()))
discount_values.sort()
item_values.sort()
item_values.reverse()
# print(item_values)
# print(discount_values)
basket_size = discount_values[0]
result = 0
bought = 0
counter = 0
while bought < target:
    if  target - bought < basket_size:
        result += sum(item_values[counter:])
        bought += target + 1
    else:
        bought += 2 + basket_size
        result += sum(item_values[counter:counter + basket_size])
        counter += 2 + basket_size

print(result)
