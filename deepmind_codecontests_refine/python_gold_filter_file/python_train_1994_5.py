def make_right(lst):
    if len(lst) == 1:
        return 0
    d = lst[-1] - lst[0]
    if d % 2 == 0:
        flag = True
        for i in range(len(lst)):
            if lst[i] != lst[0] and lst[i] != lst[-1] and lst[i] != lst[0] + d // 2:
                flag = False
        if flag:
            return d // 2
    flag = True
    for i in range(len(lst)):
        if lst[i] != lst[0] and lst[i] != lst[-1]:
            flag = False
    if flag:
        return d
    return -1


n = int(input())
b = [int(j) for j in input().split()]
print(make_right(sorted(b)))
