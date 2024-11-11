n = int(input())
x = list(map(int, input() .split()))
s,t = map(int, input() .split())
if s == t:
  print(0)
else:
  s =s-1
  t = t-1
  if s < t :
    print(min(sum(x[s:t]) , sum(x[t:])+ sum(x[:s])))
  else:
    print(min(sum(x[t:s]), sum(x[s:] ) + sum(x[:t])))
