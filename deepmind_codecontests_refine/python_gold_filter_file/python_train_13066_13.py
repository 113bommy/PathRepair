s1 = input().split()
length = int(s1[0])
max_k = int(s1[1])
s2 = input()

arr = s2.split()
start = 0
end = 0
dist = dict()
s = start
max_l = 0
for i in range(length):
    cur = arr[i]
    if cur not in dist:
        dist[cur] = 1
    else:
        dist[cur] += 1
    k = len(dist)
    l = i - s
    if k > max_k:
        to_remove = arr[s]
        if dist[to_remove] == 1:
            dist.pop(to_remove)
        else:
            dist[to_remove] -= 1
        l -= 1
        s += 1
    if l > max_l:
        start = s
        max_l = l
        end = i


print(start + 1, end + 1)
