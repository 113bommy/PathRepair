a , b , c ,d =map (int ,input().split())
q=[]
res=0
res1=0
q.append(a)
q.append(b)
q.append(c)
q=sorted(q)
if abs(q[1]-q[0])<=d:
	res=d-abs(q[1]-q[0])
if abs(q[1]-q[2])<=d:
	res1=d-abs(q[1]-q[2])
print(res+res1)