nba=input().split()
n=int(nba[0])
b=int(nba[1])
a=int(nba[2])
s=[int(i) for i in input().split()]
ans=0
bt,at=b,a
for i in s:
    if a==0 and b==0:
        break
    ans+=1
    if i==0:
        if a>0:
            a-=1
        elif b>0:
            b-=1
        else:
            break
    else:
        if a==at:
            a-=1
        elif b>0:
            b-=1
            a = min(at,a+1)
        elif a>0:
            a-=1
        else:
            break
print(ans)