def bin(n):
    n*=1000000000
    left=0
    right=n//2
    a=n//2
    n*=1000000000
    while right-left>1:
        middle=(right+left)//2
        if (a-middle)*(a+middle)>=n:
            left=middle
        else:
            right=middle
    return [(a-left)/1000000000,(a+left)/1000000000]
t=int(input())
for i in range(t):
    n=int(input())
    if n==1 or n==2 or n==3:
        print('N')
    else:
        print('Y',*bin(n))
