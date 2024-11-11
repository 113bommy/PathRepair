n = int(input())
j = 0
for i in range(n):
    p, q  = (map(int, input().split()))
#    print(p, q)
#    print(q)
    if q - p >= 2:
#        print(q-p)
        j = j + 1
print(j)  