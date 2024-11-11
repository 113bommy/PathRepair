st = ["1", "2"]
tera = ["3", "4", "5", "6"]
for _ in range(int(input())):
    n = int(input())
    li = [input()]
    li.append(input())
    j = 0
    i = 0
    flag = 1
    while i < n:
        if li[j][i] in st:
            i += 1
        elif j == 0:
            if li[1][i] not in tera:
                flag = 0
                break
            else:
                j = 1
                i += 1
        else:
            if li[0][i] not in tera:
                flag = 0
                break
            else:
                j = 0
                i += 1
    if flag == 1 and j == 1:
        print("YES")
    else:
        print("NO")