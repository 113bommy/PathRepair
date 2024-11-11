n = int(input())
a = [int(x) for x in input().split()]
a.sort()
print(a[(n-1)//2])
