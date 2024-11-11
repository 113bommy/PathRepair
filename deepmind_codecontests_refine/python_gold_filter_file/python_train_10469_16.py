str0 = input()
counter = 0
order = 97
for i in str0:
    if abs(ord(i) - order) < 13:
        counter += abs(ord(i) - order)
    else:
        counter +=  abs(abs(ord(i) - order) - 26)
    order = ord(i)
print(counter)