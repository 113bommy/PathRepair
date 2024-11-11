n=int(input())
s=input()
t=input()
o,z=0,0
a=0
if s==t: print(0)
elif s.count('1')!=t.count('1'): print(-1)
else:
    for i in range(n):
        a+=int(s[i])-int(t[i])
        o=max(a,o)
        z=min(a,z)
    print(o-z)