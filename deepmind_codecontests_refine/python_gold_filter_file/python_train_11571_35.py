x,y=map(int,input().split())
t=x-y
print(y+((t*(t+1)//2)-1) if x>y else x-1)