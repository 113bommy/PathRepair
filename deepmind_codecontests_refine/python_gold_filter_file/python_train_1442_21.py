r,g,b=map(int,input().split())
print(["NO","YES"][(10*g+b)%4==0])