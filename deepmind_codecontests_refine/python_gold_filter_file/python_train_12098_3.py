t=int(input())
out = []
for i in range(t):
  n=int(input())
  out = ['0']
  start=n+1
  end=n
  while start > 0 and end > 0 and int(n/start) != int(n/end):
    out.append(str(int(n/end)))
    start=int(n/int(n/end))
    end=min(start-1,int(n/(int(n/end)+1)))
  print(len(out))
  print(' '.join(out))