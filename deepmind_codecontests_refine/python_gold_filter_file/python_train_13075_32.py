n,m = map(int,input().split())
s=input()
t=input()
ans=[0]*(len(t) - len(s) + 1)
for i in range(len(t) - len(s) + 1):
    for j in range(len(s)):
        if(t[i+j] == s[j]):
            ans[i] +=1
pt = max(ans)
ind = ans.index(pt)
j=0
#print(ans)
lol=''
ctr=0
for i in range(ind, ind+len(s)):
    if(t[i] != s[j]):
        lol+=str(j+1)+" "
        ctr+=1
    j+=1
print(ctr)
print(lol[:-1])
