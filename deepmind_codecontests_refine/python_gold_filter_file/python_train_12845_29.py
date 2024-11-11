r= lambda x:(x*(x+1))//2
a,b=map(int,input().split())
if r(a-1)<=b:exit(print("no solution"))
for i in range(a):print(0,0+i)