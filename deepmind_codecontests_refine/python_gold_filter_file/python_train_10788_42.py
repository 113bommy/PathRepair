def check_list(lst1):
    count1 = 0
    count2 = 0
    for elem in lst1:
        if elem > 0:
            count1 += 1
        else:
            count2 += 1
    if count1 != 0 and count2 != 0:
        if count1 == count2 != 1:
            return "No"
        elif count1 != 1 and count2 > count1:
            return "No"
        elif count2 != 1 and count1 > count2:
            return "No"
    return "Yes"


n = int(input())
a = list()
for i in range(n):
    x, y = [int(j) for j in input().split()]
    a.append(x)
print(check_list(a))
