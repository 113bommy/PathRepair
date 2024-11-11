n = int(input())
L = [int(i) for i in input().split()]

L.sort()
# print(L)
if n%2 != 0:
    remove = (n-1)//2
else:
    remove = (n-1)//2
print(L[remove])
