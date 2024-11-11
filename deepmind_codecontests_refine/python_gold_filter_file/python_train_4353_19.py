N=int(input())
d=[input().split()+[i+1] for i in range(N)]
d.sort(key=lambda x:(x[0],-int(x[1])))
for i in d:
  print(i[2])