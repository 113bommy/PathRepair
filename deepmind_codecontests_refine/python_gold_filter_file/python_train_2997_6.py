K=int(input())
import queue
q=queue.Queue()
for i in range(1,10):
  q.put(i)
for j in range(1,K+1):
  x=q.get(j)
  if x%10!=0:
    q.put(10*x+x%10-1)
  q.put(10*x+x%10)
  if x%10!=9:
    q.put(10*x+x%10+1)
print(x)