n,r,s,x=int(input()),1,0,1
while x<=n//10:
    x*=10
    s+=9*r*x//10
    r+=1
x=n-x+1
s+=r*x
print(s)