n, k = map(int, input().split())
lst = list(map(int, input().split()))
if k >= n-1:
    print(max(lst))
else:
    cnt = 0
    temp = lst[0]   
    while(True):
        if temp > lst[1]:
            cnt += 1
            lst.append(lst[1])
            lst.pop(1)
        else:
            lst.append(temp)
            lst.pop(0)
            temp = lst[0]
            cnt = 1
        if(cnt == k):
            print(temp)
            break

