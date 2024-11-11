import collections
n,q=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]
counter=max(a)
answer=[]
b=collections.deque(a)
while 1:
    if b[0]==counter:
        x=b.popleft()
        c=[]
        for i in range(n-1):
            c.append(b.popleft())
        break
    x=b.popleft()
    y=b.popleft()
    b.appendleft(max(x,y))
    b.append(min(x,y))
    answer.append((x,y))
lena=len(answer)
for i in range(q):
    a=int(input())
    if a<=lena:
        print(*answer[a-1])
    else:
        print(counter,c[(a-lena-1)%(n-1)])
        
