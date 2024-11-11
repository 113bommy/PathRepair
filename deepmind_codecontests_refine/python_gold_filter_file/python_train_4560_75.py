N,K=input().split()
N,K=[int(N),int(K)]
A=list(map(int,input().split()))
F=list(map(int,input().split()))

A=sorted(A)
F=sorted(F,reverse=True)

goal_max=10**12+1
goal_min=0-1

while(goal_max-goal_min!=1):
   goal=(goal_max+goal_min)//2
   counter=0

   for i in range(N):
      counter+=max(0,A[i]-goal//F[i])

   if(counter<=K):
      goal_max=goal

   else:
      goal_min=goal
      
print(goal_max)