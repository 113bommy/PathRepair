n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
ov = []
un = 0
cnt = 0
for i in range(n):
  c = a[i]-b[i]
  if c >= 0:
    ov.append(c)
  else:
    un += c
    cnt += 1
if un == 0:
  print(0)
else:
  un *= -1
  ov.sort(reverse=True)
  ov2 = 0
  for i in range(len(ov)):
    ov2 += ov[i]
    if ov2 >= un:
      print(cnt+i+1)
      break
  else:
    print(-1)