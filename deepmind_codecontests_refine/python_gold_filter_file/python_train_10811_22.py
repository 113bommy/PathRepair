n = int(input())
s = input()
x = 0
j = 0
for i in range(len(s)):
  j = j + (s[i]=='I') - (s[i]=='D')
  x = max(x,j)
print(x)
