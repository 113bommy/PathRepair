n,k=map(int,input().split())
s=set()
for i in range(k):
  _=input()
  s|=set(input().split())
print(n-len(s))