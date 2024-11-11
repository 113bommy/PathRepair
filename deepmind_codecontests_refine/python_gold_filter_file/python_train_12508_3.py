from heapq import heappop, heapify


def get_max(l, r):
    return max(a[l: r + 1])


n, k = [int(item) for item in input().split()]
a = [int(item) for item in input().split()]

coaches = [set(), set()]

coach = 0
taken = 0

l, r = 0, 0
still_map = {0: n - 1}
done_map_l = {}
done_map_r = {}

global_map = {}
for i in range(n):
    global_map[a[i]] = i

done = [0] * (n + 1)
h = [-(i + 1) for i in range(n)]
heapify(h)
# print(a)
while taken < n:
    # max_index = -1
    # mx = -float("inf")
    # mx_l = -1
    # for l in still_map:
    #     r = still_map[l]
    #     local_max = get_max(l, r)
    #     if local_max > mx:
    #         mx = local_max
    #         mx_l = l
    local_max = -heappop(h)
    while done[local_max]:
        local_max = -heappop(h)

    max_index = global_map[local_max]

    l_search, r_search = max_index - 1, max_index + 1
    l_count, r_count = 0, 0
    l_last = max_index

    while l_search >= 0 and l_count < k:
        if l_search in done_map_r:
            new_l_search = done_map_r[l_search] - 1
            done_map_l[done_map_r[l_search]] = l_last
            done_map_r[l_last] = done_map_r[l_search]

            l_search = new_l_search
        else:
            l_count += 1
            coaches[coach].add(l_search)
            done[a[l_search]] = 1
            taken += 1
            l_search -= 1

    r_last = l_search + 1
    while r_search < n and r_count < k:
        if r_search in done_map_l:
            new_r_search = done_map_l[r_search] + 1
            done_map_r[done_map_l[r_search]] = r_last
            done_map_l[r_last] = done_map_l[r_search]

            r_search = new_r_search
        else:
            r_count += 1
            coaches[coach].add(r_search)
            done[a[r_search]] = 1
            taken += 1
            r_search += 1

    done[local_max] = 1
    coaches[coach].add(max_index)
    taken += 1
    coach ^= 1
    done_map_l[l_search + 1] = r_search - 1
    done_map_r[r_search - 1] = l_search + 1
    # print(done_map_l, done_map_r)
    # print(coaches, l_search, r_search)


print(''.join('1' if i in coaches[0] else '2' for i in range(n)))
