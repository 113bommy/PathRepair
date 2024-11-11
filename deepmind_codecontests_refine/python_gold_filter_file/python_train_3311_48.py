r,g,b,n=map(int,input().split())
cnt=0
for i in range(n+1):
    for j in range(n-i+1):
        k=n-(i+j)
        if k>=0 and i%r==j%g==k%b==0:
            cnt+=1
print(cnt)
