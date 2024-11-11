I = input
for _ in range(int(I())):
    n, k = map(int, I().split())
    ans=['a' for i in range(n)]
    if k>2:
        for i in range(n,2,-1):
            t=((i-1)*(i-2))//2
            t+=1
            u=((i)*(i-1))//2
            if t<=k<=u:
                d=k-t
                ans[n-i]='b'
                ans[n-d-1]='b'
                break
        print(''.join(ans))
    else:
        if k==1:
            print('a'*(n-2),end='')
            print('bb')
        else:
            print('a'*(n-3),end='')
            print('bab')
