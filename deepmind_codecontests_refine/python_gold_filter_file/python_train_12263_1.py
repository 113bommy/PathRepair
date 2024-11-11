n=int(input())
if n+1>int((n+1)/1.08)*1.08>=n:
  print(int((n+1)/1.08))
else:
  print(':(')
