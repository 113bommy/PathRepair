n,x=map(int,input().split())
sum=x
count=0
for i in range(n):
    a,b=input().split()
    b=int(b)
    if(a=='+'):
        sum=sum+b
    elif a=='-' and sum>=b:
        sum=sum-b
    else:
        count+=1
print(sum,count)


