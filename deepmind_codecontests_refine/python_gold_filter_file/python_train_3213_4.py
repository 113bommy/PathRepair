a,b,x=map(int,input().split())
print(b//x-(a-1)//x if a>0 else b//x+1)