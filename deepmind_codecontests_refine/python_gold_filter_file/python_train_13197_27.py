n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
total = a[0]
for i in range(n-2):
    total += a[i//2+1]
print(total)
