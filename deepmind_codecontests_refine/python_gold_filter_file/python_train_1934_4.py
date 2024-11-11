n = int(input())
print(n//2)
for i in range(n//2-1):
    print(2, end=' ')
print(2+n%2)