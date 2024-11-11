x,y,z,k = map(int,input().split())

info = [list(map(int,input().split())) for i in range(3)]

li = []
ans = []
li_append = li.append 
ans_append = ans.append

for i in info[0]:
  for j in info[1]:
    li_append(i+j)
li = sorted(li,reverse=True)

for i in li[:3000]:
  for j in info[2]:
    ans_append(i+j)
ans = sorted(ans,reverse = True)

for i in range(k):
  print(ans[i])