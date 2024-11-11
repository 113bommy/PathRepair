for _ in range(int(input())):
    n,m=map(int,input().split())
    if (n-m+1)%2!=0  and n-m+1>0:
        print("YES")
        print('1 '*(m-1)+str(n-m+1))
    elif  (n-2*(m-1))%2==0  and n-2*(m-1)>0:
        print("YES")
        print('2 '*(m-1)+str(n-2*(m-1)))
    else:
        print("NO")