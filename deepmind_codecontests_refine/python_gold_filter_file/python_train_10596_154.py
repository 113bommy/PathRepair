N,K = map(int,input().split())
a = 1
while K**a <= N:
  a = a + 1
print(a)