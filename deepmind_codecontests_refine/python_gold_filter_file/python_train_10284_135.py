K = int(input())
A, B = map(int,input().split())

N = B // K
if N * K < A:
  print("NG")
else:
  print("OK")