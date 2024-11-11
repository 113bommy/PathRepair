d={}
l=[]

for _ in range(int(input())):

  name,score = input().split()
  score=int(score)
  
  d[name]=d.get(name,0) + score
  l.append([name,d[name]])


m=max(d.values())

for name,score in l:
  if d[name]>=m and score>=m:
    print(name)
    break