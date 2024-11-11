n, m, k = [int(i) for i in input().split()]
arr = []
start = 0
end = m
cont = 1
for i in range(n):
    for j in range(start, end, cont):
        arr.append(i+1)
        arr.append(j+1)
    if start == 0:
        start = m-1
        end = -1
        cont = -1
    else:
        start = 0
        end = m
        cont = 1
start = 0
for i in range(k-1):
    print(*([2]+arr[start:(start+4)]))
    start += 4
print(*([n*m-((k-1)*2)]+arr[start:]))







