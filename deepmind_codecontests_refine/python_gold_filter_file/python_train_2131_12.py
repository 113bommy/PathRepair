a = int(input())
for i in range(1, 101):
    f = 0
    s = abs(a + i)
    #print(s)
    while s > 0:
        #print(s % 10)
        if s % 10 == 8:
            f = 1
        s = s // 10
    if f == 1:
        ind = i
        break
print(ind)
