n=int(input())
q,w=set(),set()
for i in range(n):
    a,b=map(int,input().split())
    q.add(a)
    w.add(b)
print(min(len(q),len(w)))
