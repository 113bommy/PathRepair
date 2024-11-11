n=int(input())
s=list(input())
count=0
l=[]
cb=0
cw=0
def swap(char ):
    if char=="W":
        return "B"
    else:
        return "W"
for i in range(len(s)):
    if s[i]=="B":
        cb+=1
    else:
        cw+=1
if (cb%2!=0) and (cw%2!=0):
    print(-1)
elif( cb==0 or cw==0):
    print(0)
else:
    for i in range(len(s)-1):
        #print(s, cb, cw, "-----1")
        if s[i]=="B":
            s[i]=swap(s[i])
            cw+=1
            cb-=1
            s[i+1]=swap(s[i+1])
            l.append(i+1)
            if s[i+1]=="B":
                cb+=1
                cw-=1
            else:
                cw+=1
                cb-=1
        if(cb==0 or cw==0):
            break
    if(cb!=0 and cw!=0):
        for i in range(len(s)-1):
            #print(s, cb, cw, "-----0")
            if s[i]=="W":
                s[i]=swap(s[i])
                cw-=1
                cb+=1
                s[i+1]=swap(s[i+1])
                l.append(i+1)
                if s[i+1]=="B":
                    cb+=1
                    cw-=1
                else:
                    cw+=1
                    cb-=1
            if(cb==0 or cw==0):
                break
    print(len(l))
    print(*l)