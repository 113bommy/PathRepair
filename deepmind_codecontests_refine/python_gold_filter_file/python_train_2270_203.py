N, K =map(int, input().split())
st = input()
print(st[:K-1] + st[K-1].lower()+st[K:])