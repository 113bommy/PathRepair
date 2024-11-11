s = input()
k = int(input())
sub = []
for i in range(len(s)):
    for j in range(i, i+5):
        sub.append(s[i:j+1])
sub = list(set(sub))
sub.sort()
print(sub[k-1])