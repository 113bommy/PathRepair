n,m=map(int,input().split())
q={-1}
while n%m not in q:q.add(n%m);n+=n%m
print("YNeos"[0not in q::2])