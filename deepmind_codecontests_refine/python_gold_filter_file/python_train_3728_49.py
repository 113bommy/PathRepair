x, y, z, k = map(int, input().split())
aaa = list(map(int, input().split()))
bbb = list(map(int, input().split()))
ccc = list(map(int, input().split()))

aabb = [a + b for a in aaa for b in bbb]
aabb.sort(reverse=True)
aabb = aabb[:k]

aabbcc = [ab + c for ab in aabb for c in ccc]
aabbcc.sort(reverse=True)
aabbcc = aabbcc[:k]

print('\n'.join(map(str, aabbcc)))
