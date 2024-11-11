ar,ans,pr,res=sorted(list(set(list(map(int,input().split(',')))))),[],-1,""
for e in ar:
    if(e==pr+1):ans[-1][1]+=1
    else:ans.append([e,e])
    pr=e
for e in ans:
    if(e[0]==e[1]):
        res+=str(e[0])
    else:
        res+=str(e[0])+'-'+str(e[1])
    res+=','
print(res[:-1])
