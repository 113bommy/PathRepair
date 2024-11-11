s=input()
z=s.count('1')
ans=len(s)+s.rfind('1')-z
if z!=1:
    ans+=2
print(ans)
