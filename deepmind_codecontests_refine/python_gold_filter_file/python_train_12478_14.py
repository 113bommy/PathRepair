n = int(input())
s = input()
t = input()
for k in range(0,n+1):
  if s[k:] == t[:n-k]:
    print(n+k)
    break