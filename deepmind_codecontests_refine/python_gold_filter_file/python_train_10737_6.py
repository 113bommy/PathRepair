n = int(input())
t = [int(x) for x in input().split()]
start = t.index(t[0] % 2 + 1)
number = t[start]
l1 = start
l2 = 0
largest = 0
for i in range(start, n):
    if t[i] == number:
        l2 += 1
    else:
        if min(l1, l2) > largest:
            largest = min(l1, l2)
        number = number % 2 + 1
        l1 = l2
        l2 = 1
if min(l1, l2) > largest:
    largest = min(l1, l2)
print(largest*2)
