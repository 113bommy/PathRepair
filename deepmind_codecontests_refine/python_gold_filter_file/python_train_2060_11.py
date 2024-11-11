n=[int(x) for x in list(input()[::-1])]+[0]
ans = 0
step = 0
for i in range(len(n)-1):
  x = n[i]+step
  if x < 5 or (x==5 and n[i+1]<5):
    ans += x
    step = 0
  else:
    ans += 10 - x
    step = 1
print(ans+step)