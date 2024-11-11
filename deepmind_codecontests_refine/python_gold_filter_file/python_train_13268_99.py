c=0
for i in range(int(input())):
    p,q=map(int,input().split())
    if(p+2<=q):
        c+=1
print(c)