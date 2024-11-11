n, k = map(int, input().split())
s = input()

f = True

for c in range (ord('a'), ord('z') + 1):
  if(s.count(chr(c)) > k):
    f = False

if f == True:
    print("YES")
else:
    print("NO")