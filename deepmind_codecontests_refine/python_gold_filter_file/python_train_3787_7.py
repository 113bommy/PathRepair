n , t= map(int,input().split())
s = input()
for _ in range(t):
  if "BG" in s:
    s = s.replace("BG", "GB")
print(s)