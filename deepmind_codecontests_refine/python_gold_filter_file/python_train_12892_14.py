n = int(input())
s1 = input()
s2 = input()
count = 1
j = 0
if s1[0] == s2[0]:
  count *= 3
else:
  count *= 6 
  j += 1
while j < n-1:
  if s1[j] == s2[j]:
    if s1[j+1] == s2[j+1]:
      count *= 2
      count %= 1000000007
    else:
      count *= 2
      count %= 1000000007
      j += 1
  else:
    if s1[j+1] == s2[j+1]:
      count *= 1
      count %= 1000000007
    else:
      count *= 3
      count %= 1000000007
      j += 1
  j += 1
print(count)
