n = int(input())
a = [int(input()) for i in range(n)]
sa = sorted(a)
am, asl = sa[-1], sa[-2]
for i in range(n):
    print(asl if a[i] == am else am)