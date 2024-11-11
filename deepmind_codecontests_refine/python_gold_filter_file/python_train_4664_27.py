x,y=map(int,input().split())
x=0 if x>=4 else 4-x
y=0 if y>=4 else 4-y
print(1000000 if x==3 and y==3 else (x+y)*100000)