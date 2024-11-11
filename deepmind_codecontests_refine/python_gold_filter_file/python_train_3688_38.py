input()
a = list(map(int,input().split()))
d,e = map(int,input().split())
print(sum([a[i] for i in range(d-1,e-1)]))