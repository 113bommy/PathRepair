n = int(input())
s = input()
cnt = 0
for i in range(1000):
  num = '{:03}'.format(i)
  t=0
  for j in range(n):
    if s[j] == num[t]:
      t += 1
      if t > 2:
        cnt += 1
        break
print(cnt)
