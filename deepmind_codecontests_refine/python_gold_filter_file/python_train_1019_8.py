n = int(input())
s = list(input())

diff = s.count('.')

difflist = [diff]

for i in s:
  if i == '.':
    diff -= 1
  else:
    diff += 1
    
  difflist.append(diff)
  
print(min(difflist))