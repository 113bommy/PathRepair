x,a,b=map(int,input().split())
print(max(max(a,b)-min(a,b)-x,0))