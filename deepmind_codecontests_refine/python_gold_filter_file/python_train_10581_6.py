x,y=map(int,input().split())
r=[]
for i in range(x):
        a,b=map(int,input().split())
        r.append((a*y/b))
print(min(r))