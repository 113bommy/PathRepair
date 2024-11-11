n,k = (int(i) for i in input().split())
d = list(int(i) for i in input().split())
for i in range(n,10*n):
    si = str(i)
    flag = True
    for j in range(len(si)):
        if int(si[j]) in d:
            flag = False
            break
    if flag:
        print(si)
        break 