a, b, c, d = list(map(int, input().split()))
su1 = 0
su2 = 0
l = [a, b, c]
l.sort()
if (l[1] - l[0] < d):
    su1 = d - (l[1] - l[0])
if (l[2] - l[1] < d):
    su2 = d - (l[2] - l[1])
print(su1+su2)