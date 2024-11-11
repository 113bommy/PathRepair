n=int(input())
c=0
for l in [100,20,10,5,1]:
    c+=(n//l)
    n%=l
print(c)