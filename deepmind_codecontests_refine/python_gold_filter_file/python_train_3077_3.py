n=int(input())

s=input()

S=[]
e=""

for i in range(len(s)):
    if(s[i] in ".?!"):
        e+=s[i]
        S.append(e)
        e=""
    else:
        e+=s[i]

acc=0
ans=0
for item in S:
    x=len(item)
    if(acc==0):
        i=0
        while(item[i]==' '):
            x-=1
            i+=1
    if(acc+len(item)<=n):
        acc+=len(item)
    else:
        if(acc==0):
            ans=-1
            break
        else:
            ans+=1
            acc=0
            i=0
            while(item[i]==' '):
                x-=1
                i+=1
            if(x>n):
                ans=-1
                break
            acc+=x
if(ans!=-1 and acc!=0):
    ans+=1
if(ans!=-1):
    print(ans)
else:
    print("Impossible")
