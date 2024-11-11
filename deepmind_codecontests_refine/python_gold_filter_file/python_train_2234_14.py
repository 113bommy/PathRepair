n, m = list(map(int, input().split()))
li = []
flag = True
while n != 0:
    if n % 2 == 0:
        n -= 2
        li.append(2)
    else:
        n -= 1
        li.append(1)
while flag:
    if len(li) % m == 0:
        flag = False
        break
    if 2 not in li:
        break
    else:
        del li[0]
        li.append(1)
        li.append(1)
if flag:
    print(-1)
else:
    print(len(li))
