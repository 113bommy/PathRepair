def ibs(bs):
    lb=0
    rb=0
    for c in bs:
        if c=='(':
            lb+=1
        elif c==')':
            if lb!=0:
                lb-=1
            else:
                rb+=1
    if(lb!=0 and rb!=0):
        return None
    elif lb!=0:
        return lb
    elif rb!=0:
        return -rb
    else:
        return 0
n=int(input())
wholecounter=0
datadic=dict()
bracs=[]
ans=0
for i in range(0,n):
    bracs.append(input())
for brac in bracs:
    temp=ibs(brac)
    if temp==None:
        continue
    elif temp==0:
        wholecounter+=1
    else:
        datadic[temp]=datadic.get(temp,0)+1
for key in datadic:
    ans+=datadic[key]*datadic.get(-key,0)
ans=ans/2
ans+=wholecounter*wholecounter
print(int(ans))
