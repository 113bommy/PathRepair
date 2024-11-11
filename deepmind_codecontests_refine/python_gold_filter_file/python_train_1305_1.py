l = input()
l = l.split(" ")
a = int(l[0])
b = int(l[1])
c = int(l[2])

res = False

if (c == 0):
    res = a == b
elif (b < a and c > 0) or (b > a and c < 0):
    res = False
elif (b >= a and c > 0) or (b <= a and c < 0):
    res = ((b-a)%c) == 0

if res: print("YES")
else: print("NO")
