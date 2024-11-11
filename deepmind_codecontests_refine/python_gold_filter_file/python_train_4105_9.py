input()
l=list(map(int,input().split()))
a=l.index(max(l))
l.remove(max(l))
l.sort()
print(a+1,l[-1],sep=' ')


