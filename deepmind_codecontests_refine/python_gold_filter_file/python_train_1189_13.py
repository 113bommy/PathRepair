import math
test = 1
for tes in range(test):
    n,m=list(map(int, input().split()))
    if m>=2*n:
        m = m-2*n
        if(m>2):
            print(-1)
            continue
        print('110'*n + '1'*m)
    elif n>m+1:
        print(-1)
    elif n==m+1:
        print('01'*(m) +'0')
    else:
        print('110'*(m-n)+'10'*(2*n-m))
