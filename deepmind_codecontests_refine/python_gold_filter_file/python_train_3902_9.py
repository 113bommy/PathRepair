n, m=list(map(int, input().split()))
s1='#'*m
s2='#'.rjust(m, '.')
s3='#'.ljust(m, '.')
flag=0
for i in range(n):
    if i%2==0:
        print(s1)
    else:
        if flag%2==0:
            print(s2)
        else:
            print(s3)
        flag+=1