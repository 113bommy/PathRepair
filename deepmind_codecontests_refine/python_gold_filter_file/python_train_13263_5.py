l=[int(i) for i in input().split(',')]
l=list(set(l))
#print(l)
ans=''
l.sort()
i=0 
res=[]
for i in range(1,10000):
    if i>max(l):
        break 
    if i in l:
        res.append(i)
    else:
        if len(res)==1 :
            ans+=str(res[0])+','
        elif len(res)>1:
            ans+=str(res[0])+'-'+str(res[-1])+','
        res=[] 
if len(res)==1:
    ans+=str(res[0])
elif len(res)>1:
    ans+=str(res[0])+'-'+str(res[-1])
ans=list(ans)
if ans[-1]==',':
    ans.pop()
print(''.join(ans))