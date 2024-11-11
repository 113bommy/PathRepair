n = int(input())
a = [int(s) for s in input().split()]
a.sort()
print(a[(n-1)//2])