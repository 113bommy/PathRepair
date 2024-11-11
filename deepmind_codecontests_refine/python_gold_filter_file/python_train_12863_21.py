n,m= map(int,input().split())
for i in range(1,11):
    if (i*n)%10==0 or (i*n)%10==m:
        print(i)
        break