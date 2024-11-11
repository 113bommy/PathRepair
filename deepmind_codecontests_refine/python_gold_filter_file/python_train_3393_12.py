def moves(s1,s2):
    if s1!=s2:
        count=1
        while s1!=s2[count:]+s2[:count] and count<=len(s1):
            count+=1
        if count>len(s1):
            return -1
        else:
            return count
    else:
        return 0

n=int(input())
s=[]
for i in range(n):
    s.append(input())
ans=[0]*n
#m=len(s[0])
y=True
for i in range(n):
    j=0
    while j<n and y:
        z=moves(s[i],s[j])
        if z==-1:
            y=False
        else:
            ans[i]+=z
            #ans[j]+=m-z
            j+=1
    if y==False:
        print(-1)
        exit(0)
print(min(ans))
