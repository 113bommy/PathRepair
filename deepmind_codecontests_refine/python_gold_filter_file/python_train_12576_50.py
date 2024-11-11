N=int(input())
ba=bx=xa=0
ans=0
for i in range(N):
    s=input()
    ans+=s.count('AB')
    if s.startswith('B') and s.endswith('A'):
        ba+=1
    elif s.startswith('B'):
        bx+=1
    elif s.endswith('A'):
        xa+=1

if ba==0:
    ans+=min(bx,xa)
elif ba>0:
    if bx+xa>0:
        ans+=ba+min(bx,xa)
    elif bx+xa==0:
        ans+=ba-1

print(ans)