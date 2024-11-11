for _ in range(int(input())):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))

    flag=0
    for i in range(n):
        if a[i]>k:
            a[i]=2
        elif a[i]==k:
            a[i]=1
        else:
            a[i]=0

        if a[i]==1:
            flag=1

    if flag==0:
        print('no')
        continue

    if n==1:
        print('yes')
        continue

    flag=0
    for i in range(n):
        j=i+1
        while j<n and j-i<=2:
            if a[i] and a[j]:
                flag=1
                break
            j+=1
        if flag==1:
            break

    if flag==1:
        print('yes')
    else:
        print('no')



