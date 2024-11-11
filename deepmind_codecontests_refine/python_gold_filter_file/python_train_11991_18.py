s = input()
a = input()
i=0
l=[]
r=[]
for j in a:
    while s[i]!=j:
        i+=1
    l.append(i)
    i+=1
i=len(s)-1    
for j in a[::-1]:
    while s[i]!=j:
        i-=1
    r.append(i)
    i-=1
r.reverse()    
ans=r[0] 
for i in range(len(a)-1):
    ans = max(ans,r[i+1]-l[i]-1)  
ans = max(ans,len(s)-l[-1]-1) 
print(ans)            
