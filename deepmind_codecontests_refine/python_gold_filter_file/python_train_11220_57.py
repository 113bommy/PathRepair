n=int(input())
A=sorted(list(map(int,input().split())))
s=1
for a in A:
  s*=a
  if s>10**18:
    print(-1)
    exit()
print(s)