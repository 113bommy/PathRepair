def BubbleSort(alist):
    for i in range(len(alist)-1,0,-1):
        flag = 0
        for k in range(i):
            if alist[k]>alist[k+1]:
                alist[k] , alist[k+1] = alist[k+1] , alist[k]
                flag=1
        if flag==0:
             break
    return alist
n,m=map(int,input().split())
a = [int(x) for x in input().split()]
a=BubbleSort(a)
if m>n:
    print(-1)
else:
    print(a[n-m],0)