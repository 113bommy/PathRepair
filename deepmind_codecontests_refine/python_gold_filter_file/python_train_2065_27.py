n = input()
s = list(map(int, input().split()))
ans = 0

while all(a%2==0 for a in s):
  ans +=1
  s = [a/2 for a in s]

print(ans)