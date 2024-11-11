n,a,b,c,t=map(int,input().split(" "))
s=map(int,input().split(" "))
s = list(s)
sum=n*a
for i in range(0,n):
    if(b<c):
        sum+=(t-s[i])*(c-b)
print(sum)

    
