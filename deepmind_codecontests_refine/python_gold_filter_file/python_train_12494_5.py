cross_section = input()
visited = {0: -1}
height = 0
pools = []
for i, c in enumerate(cross_section):
    if c == '\\':
        height -= 1
    elif c == '/':
        height += 1
        if height in visited:
            width = i - visited[height]
            sm = 0
            while pools and pools[-1][0] > visited[height]:
                _, volume = pools.pop()
                sm += volume
            pools.append((i, sm + width - 1))
    visited[height] = i

print(sum(v for _, v in pools))
print(len(pools), *(v for _, v in pools))