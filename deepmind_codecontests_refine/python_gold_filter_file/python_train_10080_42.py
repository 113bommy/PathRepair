s=input()
k=int(input())
a={s}
for i in range(k):
  for j in range(len(s)-i):a.add(s[j:j+i+1])
print(sorted(list(a))[k-1])