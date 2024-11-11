n=int(input())
s=input()
s=s.lower()
if (n<26):
  print("NO")
if (n>=26):
  if (len(set(s))==26):
    print("YES")
  if (len(set(s))!=26):
    print("NO")  