a, b = input().split()
mugs = input().split()

sortedMugs = sorted(mugs)
##print(sortedMugs)
total  = 0 
for i in range(int(a)-1):
  total += int(sortedMugs[i])
  
if total > int(b):
  print("NO")
else:
  print("YES")
  