a,b=map(int,input().split())
z=[0]+[1]*a
for _ in " "*b:
    gh=input().split()
    if gh[2]=='left':z[int(gh[-1]):]=[0]*(a-int(gh[-1])+1)
    else:z[:int(gh[-1])+1]=[0]*(int(gh[-1])+1)
if z[1:].count(1):print(z[1:].count(1))
else:print(-1)