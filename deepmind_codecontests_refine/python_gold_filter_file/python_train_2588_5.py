H,W,N = map(int,input().split())

A = {}
for i in range(N):
  a,b = map(int,input().split())
  a-=1;b-=1
  for t in range(3):
    for s in range(3):
      if 0<=a-t<H-2 and 0<=b-s<W-2:
        if (a-t,b-s) not in A:
          A[(a-t,b-s)]  = 1
        else:
          A[(a-t,b-s)]  += 1
#print(A)
ans = [-1]
temp = list(A.values())
total = 0
for i in range(1,10):
  c = temp.count(i)
  total += c
  ans.append(c)
ans[0] = (H-2)*(W-2)-total
print(*ans, sep="\n")

  