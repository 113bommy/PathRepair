count = int(input())
number = [int(i) for i in input().split()]
max = -1
for i in range(0, count):
    tmp = number[i]
    if tmp > max:
        max = tmp
    if not i + 1 == count:    
        for j in range(i + 1, count):
            tmp = tmp ^ number[j]
            if tmp > max:
                max = tmp
print("%d" % max)