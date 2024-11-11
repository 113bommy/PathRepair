numbers = [2, 7, 2, 3, 3, 4, 2, 5, 1, 2]
n = input()
a = 1
for x in n:
    a *= numbers[int(x)]
print(a)