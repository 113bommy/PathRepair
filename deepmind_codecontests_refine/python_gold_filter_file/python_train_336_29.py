n=int(input())-1
a=1
m=10**9+7
for i in range(2,n+2):a=a*i%m
print((a-2**n)%m)