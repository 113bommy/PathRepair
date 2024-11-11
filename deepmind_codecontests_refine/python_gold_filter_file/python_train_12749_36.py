f=lambda:map(int,input().split())
n,m=f()
s=sorted(f())
print(max([s[0],m-s[n-1]]+[(b-a)/2 for a,b in zip(s,s[1:])]))