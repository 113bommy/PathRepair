#t=int(input())
#for z in range(t):
n=int(input())
s=input()
#n=len(s)
a=[]
c="aeiouy"
ans=""
a.append(s[0])
j=0
for i in range(1,n):
    if a[j] in c and s[i] not in c:
        a.append(s[i])
        j+=1
    elif a[j] not in c:
        a.append(s[i])
        j+=1
for i in a:
    ans+=i
print(ans)
    
    
    
        
        
    
