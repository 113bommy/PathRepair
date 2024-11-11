n,m=[int(x) for x in input().split()]
if(m==n and n==1):
    print(1)
elif(m>n/2):
    print(m-1)
else:
    print(m+1)
