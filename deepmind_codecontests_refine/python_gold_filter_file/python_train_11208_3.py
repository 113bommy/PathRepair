n = int(input())
a = input()
num = 0
L = []
for i in range(n):
    if a[i] == 'x':
        num += 1
    elif a[i] != 'x':
        if num > 0:
            L.append(num)
        num = 0
if num > 0:
    L.append(num)
sum_num = 0
for i in L:
    sum_num += max(0, i - 2)
print(sum_num)
