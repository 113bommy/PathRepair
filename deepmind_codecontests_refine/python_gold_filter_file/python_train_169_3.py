n=int(input())
s=input()
l={}
i=0
for i in range(len(s)-1):
    ss=s[i]+s[i+1]
    if ss in l:
        l[ss]=l[ss]+1 
    else:
        l[ss]=1 
# print(l)
ll=list(sorted(l.items(), key = lambda kv:(kv[1], kv[0])))
# print(ll)
sss=str(ll[len(ll)-1])
print(sss[2]+sss[3])
