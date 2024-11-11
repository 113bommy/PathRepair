a,b,n=map(int,input().split())
s=min(b-1,n)
print(int((a*s)/b)-a*int(s/b))