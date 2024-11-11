n,x=list(map(int,input().split()))
dis=0
for i in range(n):
    s=input().split()
    if(s[0]=="+"):
        x+=int(s[1])
    else:
        if (x-int(s[1]))>=0:
            x-=int(s[1])
        else:
            dis+=1
print (x,dis)
