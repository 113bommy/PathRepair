s = input()
k = int(input())
n = len(s)
a = set()
for i in range(5):
    for j in range(n-i):
        a.add(s[j:j+i+1])
a = sorted(list(a))
print(a[k-1])