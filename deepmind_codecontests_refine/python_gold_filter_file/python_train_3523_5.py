h,w=map(int,input().split())
n=input()
v=[]
for i,a in enumerate(list(map(int,input().split()))):
    v+=[i+1]*a
for j in range(h):
    if j%2==0:
        u = v[w*j:w*(j+1)]
    else:
        u = v[w*(j+1)-1:w*j-1:-1]
    print(" ".join(map(str,u)))