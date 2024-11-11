
a1, a2, a3, a4 = [int(i) for i in input().split()]

index1 = 1
index2 = 2
index3 = 3
index4 = 4

s = input()
counter = 0

for i in s:
    if int(i) == index1:
        counter += a1
    if int(i) == index2:
        counter += a2
    if int(i) == index3:
        counter += a3
    if int(i) == index4:
        counter += a4
print(counter)
