n = int(input())
a = [int(i) for i in input().split()]
m = max(a)
s = sum(a)
print(2*m-s+1)
