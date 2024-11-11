r,g,b,n=map(int,input().split())
cnt=0
for i in range(n//r+1):
    for j in range(n//g+1):
        if (n-i*r-j*g)%b==0 and n-i*r-j*g>=0:
            cnt+=1
print(cnt)