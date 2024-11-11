def buggy_sort(n):
    if n<=2:
        print(-1)
        return
    else:
        t=100
        a=[]
        for i in range(55):
            a.append(t)
            t=t-1

        for i in range(n):
            print(a[i],end=' ')





n=int(input(''))
buggy_sort(n)