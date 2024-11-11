n=int(input())
s=list(input().strip().split() for _ in range(n))
x=input().strip()

ans=0
isis=False
for ss,tt in s:
  if isis:
    ans += int(tt)
  if ss==x:
    isis=True
print(ans)
