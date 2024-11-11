



n = int(input())


t = list(map(int,input().split()))


if n<=2:
    print(0)
else:
    p=0
    for k in range(1,n-1):

        if t[k-1]>t[k]<t[k+1] or t[k-1]<t[k]>t[k+1]:
            p+=1

    print(p)
