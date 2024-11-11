w, h, k = map(int, input().split())

p = 0
for i in range(k):
    wu = w-4*i
    hu = h-4*i
    p += (2*(wu+hu)-4)

print(p)