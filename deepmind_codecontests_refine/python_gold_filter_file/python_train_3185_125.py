l,b=list(map(int,input().split()))
c=0
while(b>=l):
    l=l*3
    b=b*2
    c+=1
print(c)