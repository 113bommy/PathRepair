x=int(input())
t=input()
ans=0
def sub(t):
    ti=list(map(int, t.split(" ")))
    ti[1]-=x
    if(ti[1]<0):
        ti[0]-=1
        ti[1]=60+ti[1]
        if(ti[0]<0):
            ti[0]=24+ti[0]
    return str(ti[0]) + " " + str(ti[1])

while("7" not in t):
    t=sub(t)
    ans+=1
print(ans)
exit()

