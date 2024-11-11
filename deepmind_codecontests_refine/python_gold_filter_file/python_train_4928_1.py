n,a,b=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
print(l[-a]-l[b-1])