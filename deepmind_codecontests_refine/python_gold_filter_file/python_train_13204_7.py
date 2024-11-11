n = str(input())
lis = [0 for i in range(26)]
ans = 1
for i in range(len(n)):
  ans += i
  lis[ord(n[i])-ord("a")] += 1
for i in range(26):
  for k in range(lis[i]-1):
    ans -= (k+1)
print(ans)