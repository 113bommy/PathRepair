n=int(input())
s=[list(input()) for _ in range(3)]
cnt=0
for i in range(n):
  cnt+=len(set([s[0][i],s[1][i],s[2][i]]))-1
print(cnt)