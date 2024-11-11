s = input()
k = int(input())
l = []
for i in range(1,k+1):
    for j in range(len(s)-i+1):
        l.append(s[j:j+i])


l = list(set(l))
l.sort()
print(l[k-1])