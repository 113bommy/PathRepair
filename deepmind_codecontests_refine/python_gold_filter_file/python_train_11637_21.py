def II():return int(input())
def LI():return list(map(int,input().split()))                     
from collections import Counter, deque

n=II()
a=LI()
b=LI()



ac=Counter(a)
bc=Counter(b)
abc=ac+bc
for i in abc.values():
  if i>n:
    print("No")
    exit()
    
print("Yes")
a=deque(a)
b=deque(b)
ans=[]
b.rotate(n//2)
while a:
  if a[0]!=b[0]:
    a.popleft()
    ans.append(b.popleft())
  else:
    b.rotate()
print(*ans)
