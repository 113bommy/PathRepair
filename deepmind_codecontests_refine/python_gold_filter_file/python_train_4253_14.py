A=list(input())
from collections import deque
A=deque(A)
cnt=0
while len(A)>1:
   if A[0]==A[-1]:
      A.pop()
      A.popleft()
   elif (A[0]!="x" and A[-1]=="x" ):
      cnt+=1
      A.pop()
   elif (A[0]=="x" and A[-1]!="x" ):
      cnt+=1
      A.popleft()
   else:
      print(-1)
      exit()
print(cnt)