s = input()
k = int(input())

substrings = set()
n = len(s)
for i in range(n):
  for j in range(1,k+1):    
    substrings.add(s[i:i+j])
    
print(sorted(substrings)[k-1])