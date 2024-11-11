n = int(input())
if(n > 2):
    lst = list(map(int, input().split()))
    lst.sort()
    res = max(lst) - min(lst)
    for i in range(2):
        res = int(min(res,lst[n+i-2]-lst[i]))
    print(res)   
if(n == 2):
    lst = list(map(int, input().split()))
    print('0')