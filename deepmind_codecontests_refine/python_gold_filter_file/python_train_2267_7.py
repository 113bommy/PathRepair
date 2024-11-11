X,N=map(int,input().split())
P=sorted(list(map(int,input().split())))
t=0
for i in range(0,102):
    if i not in P:
        if abs(X-t)>abs(X-i):
            t=i
print(t)