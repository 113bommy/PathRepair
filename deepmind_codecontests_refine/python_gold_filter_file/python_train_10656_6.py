n = l = r = minl = maxr = 0
number = 1
n = int(input(""))
minl, maxr = map(int, input().split())

for i in range(2,n+1):
    l, r = map(int, input().split())
    if (l <= minl and r >= maxr):
        number = i
    elif (l < minl or r > maxr):
         number = -1
    minl = min(minl, l)
    maxr = max(maxr, r)
print(number)