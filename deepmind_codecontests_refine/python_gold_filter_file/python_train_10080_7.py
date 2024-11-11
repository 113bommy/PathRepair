s = input()
k = int(input())
subs = []

for i in range(len(s)):
    for j in range(k):
        subs.append(s[i:i+j+1])

subs = sorted(list(set(subs)))
print(subs[k-1])
