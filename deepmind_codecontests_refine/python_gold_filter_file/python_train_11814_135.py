m,n= list(map(int, input().split()))

if(m%2==0 and n%2==0):
    sum=m*n/2
elif (m%2!=0 and n%2!=0):
    sum=(m*n)//2
else:
    sum=m*n/2


print(int(sum))