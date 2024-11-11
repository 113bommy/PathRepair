a,b,c=map(int,input().split())
print(max(max([b,c])-min([b,c])-a,0))