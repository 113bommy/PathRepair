n, m = input().split()
n = int(n)
m = int(m)
l = 0
r = 0
t1 = 0
t2 = 0
ar1 = input().split()
ar2 = input().split()
for i in range(n):
    ar1[i] = int(ar1[i])
    ar2[i] = int(ar2[i])
for i in range(n):
    t1 += ar2[i]
    l += max(0, ar1[i] - m * t1)
for i in range(n - 1, -1, -1):
    t2 += ar2[i]
    r += max(0, ar1[i] - m * t2)
if(l > r):
    print("Limak")
elif(l == r):
    print("Tie")
else:
    print("Radewoosh")