nums = int(input())
counter = 0
list1 = [int(h) for h in input().split()]
if sum(list1) % 2 == 0:
    for i in list1:
        if i % 2 == 0:
            counter += 1
    print(counter)
if sum(list1) % 2 != 0:
    for i in list1:
        if i % 2 != 0:
            counter += 1
    print(counter)