n=int(input())
l=[0,0,0,0]#non,~a,b~,b~a
ans=0
for i in range(n):
    s=input()
    ans+=s.count("AB")
    l[2*int(s[0]=="B")+1*int(s[-1]=="A")]+=1

if l[-1]:
    ans+=l[-1]-1
    if l[1]:
        l[1]-=1
        ans+=1
    if l[2]:
        l[2]-=1
        ans+=1
print(ans+min(l[1:3]))