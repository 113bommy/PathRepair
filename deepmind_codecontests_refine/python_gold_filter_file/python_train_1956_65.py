x,y=map(int,input().split())
x=x%y
print(min(x,y-x))