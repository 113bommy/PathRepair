from collections import*
n,*a=map(int,open(0).read().split())
def f(a):
  a=deque(a)
  deq=deque([a.popleft()])
  for i in range(n-1):
    if i%4==0:
      deq.appendleft(a.pop())
    elif i%4==1:
      deq.append(a.pop())
    elif i%4==2:
      deq.appendleft(a.popleft())
    else:
      deq.append(a.popleft())
  l=list(deq)
  return sum(abs(i-j)for i,j in zip(l,l[1:]))
s=sorted(a)
print(max(f(s),f(s[::-1])))
