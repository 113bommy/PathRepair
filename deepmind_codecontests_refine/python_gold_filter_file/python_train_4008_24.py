n,w=map(int,input().split())
l=sorted(list(map(int,input().split())))
print(min(w,min(l[n]/2,l[0])*3*n))