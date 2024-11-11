m,n=map(int,input().split())
for i in range(1,10):
    if m*i%10==0 or m*i%10==n:
        print(i)
        break
