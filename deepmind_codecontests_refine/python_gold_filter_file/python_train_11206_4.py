n, k = [int(i) for i in input().split()]

s = set()

for i in range(1, k+1):
    if n % i in s:
        print("No")
        break
    s.add(n % i)
else:
    print("Yes")