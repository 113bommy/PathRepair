a,b,x = map(int,input().split())
print(b//x-a//x if a%x!=0 else b//x-a//x+1)
