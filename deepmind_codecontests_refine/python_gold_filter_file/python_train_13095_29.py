n = int(input())
s = input()
l =[s[0]]
for c in s:
  if c != l[-1]:
    l.append(c)
print(len(l))