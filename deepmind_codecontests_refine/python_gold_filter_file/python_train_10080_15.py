s = input()
k = int(input())
u = [s[i:i+j+1] for i in range(len(s)) for j in range(k+1)]
a = list(set(u))
a.sort()
print(a[k-1])