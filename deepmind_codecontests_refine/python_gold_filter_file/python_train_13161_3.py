s1 = input()
s2 = input()
l=j= len(s2)
for i in range(l):
    if s1[i] != s2[i]:
        j = i
        break
if s1[j+1:] != s2[j:]:
    print(0)
else:
    k = j
    while k > 0 and s1[k-1] == s1[j]:
        k -= 1
    print(j-k+1)
    print(*range(k+1,j+2))
    