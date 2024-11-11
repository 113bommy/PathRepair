S = input()
K = int(input())

tmp = set()
for i in range(len(S)):
  for j in range(5):
    tmp.add(S[i:i+j+1])
print(sorted(tmp)[K-1])