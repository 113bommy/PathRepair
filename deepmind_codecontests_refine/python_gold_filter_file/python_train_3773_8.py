for T in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
 
    arr.sort()
    lis = [0]*n
    i = n -1
    
    while i >=0 :
        a = arr.pop()
        lis[i] = a
        if len(arr) >0 :
            b = arr.pop(0)
            lis[i-1] = b
        i -=2
 
    for i in range(n):
        print(lis[i] ,end = ' ')
 
    print('\n',end = '')
    