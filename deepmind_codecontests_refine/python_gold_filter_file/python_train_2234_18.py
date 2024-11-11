n,b=map(int,input().split())
lis=[-1]
for i in range((n+1)//2,n+1):
    if i%b==0:
        lis.append(i)
        break    
print(max(lis))