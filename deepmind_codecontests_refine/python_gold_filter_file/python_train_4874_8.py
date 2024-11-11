n = int(input())
l_a = list(map(int,input().split()))
l_b = list(map(int,input().split()))
if sum(l_a)<sum(l_b):
  print(-1)
  exit()
l_sa = sorted(list(i-j for i,j in zip(l_a,l_b)))
s = 0
cou =0
#print(l_sa)
for i in l_sa:
  if i<0:
    s += i
    cou +=1
  else:
    break
#print(s,cou)
l_sb = l_sa[::-1]
for i in l_sb:
  if s<0:
    s += i
    cou += 1
    #print(s,cou)
  else:
    break
print(cou)