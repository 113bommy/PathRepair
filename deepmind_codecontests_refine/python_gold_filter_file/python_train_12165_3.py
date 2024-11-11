n,k=map(int,input().split())
li = [list(map(int, input().split())) for i in range(n)]
li.sort()
c=0
for i in range(n):
  c+=li[i][1]
  if c>=k:
    print(li[i][0])
    
    break
    