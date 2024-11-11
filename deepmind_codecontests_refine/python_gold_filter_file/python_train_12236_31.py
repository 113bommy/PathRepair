n,a,b = map(int, input().split())

if b<=0:
    steps =-1* ((-1*b)%n)
else:
    steps = b%n
goal = a+steps
if goal>n:
    goal-=n
elif goal<1:
    goal+=n
print (goal)