k = int(input())
a,b = map(int,input().split())

if k-a%k <= b-a or a%k==0:
  print("OK")
else:
  print("NG")