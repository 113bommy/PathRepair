n,a,b=map(int,input().split())
li  = [*map(int,input().split())]
li.sort()
print(abs(li[b-1]-li[b]))