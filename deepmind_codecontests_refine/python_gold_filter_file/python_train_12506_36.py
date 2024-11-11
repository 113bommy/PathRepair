n = int(input())

for i in range(n):
    l = int(input())
    num = input()
    k = 1
    while k < l:
        lsTempo = int(num[0:k])
        res = False
        if int(lsTempo) < int(num[k:l]):
                res = True
                break
        k+=1

    if res:
        print("YES")
        print(2)
        print(num[0:k], end = " ")
        print(num[k:l])
    else:
        print("NO")