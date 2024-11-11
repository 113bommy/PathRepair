n, k = [int(i) for i in input().split()]
nk = n*k
ls_ = [int(i) for i in input().split()]
marks_ = [False]*(nk+1)
c = 1
# print(ls_)

for i in ls_:
  marks_[i] = True

for i in range(k):
  print(ls_[i], end=' ')
  for j in range(1, n):
    while(marks_[c] == True):
      c+=1
    if(j != n-1):
      print(c, end=' ')
    else:
      print(c, end='')
    marks_[c] = True
  if(i != k-1):
    print()